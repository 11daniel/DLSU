package ph.edu.dlsu.mobdeve.androidchallenge.valmores.marco

import android.app.AlertDialog
import android.app.Dialog
import android.content.DialogInterface
import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import androidx.preference.isNotEmpty
import androidx.recyclerview.widget.ItemTouchHelper
import androidx.recyclerview.widget.LinearLayoutManager
import ph.edu.dlsu.mobdeve.androidchallenge.valmores.marco.adapter.PlaylistAdapter
import ph.edu.dlsu.mobdeve.androidchallenge.valmores.marco.database.PlaylistDatabase
import ph.edu.dlsu.mobdeve.androidchallenge.valmores.marco.databinding.ActivityMainBinding
import ph.edu.dlsu.mobdeve.androidchallenge.valmores.marco.databinding.DialogueInsertMediaBinding
import ph.edu.dlsu.mobdeve.androidchallenge.valmores.marco.model.PlayListMediaItem

/*  This class is open for modification. Please refer to the "TODO" keywords to know what needs to
 *  be accomplished.
 *
 *  The MainActivity handles the logic needed in the only full screen activity of the app. In this
 *  class, we should see the RecyclerView. To add a media item, the user must click on the add
 *  button (FloatActionButton), which opens up a dialogue box. The dialogue box then handles the
 *  insertion of a media item through a PlaylistDatabase instance. The MainActivity also allows for
 *  deletion of media items through swiping the ViewHolders. Modification of a media item is done by
 *  clicking on a ViewHolder. Lastly, the activity class is also in charge of getting all media
 *  items from the DB as an array list, so that the RecyclerView can properly display the
 *  information.
 */
class MainActivity : AppCompatActivity() {
    // ViewBinding used throughout the class.
    private lateinit var binding: ActivityMainBinding
    // An instance of the RecyclerView's adapter.
    private lateinit var playlistAdapter: PlaylistAdapter
    // An ItemTouchHelper instance used for handling swiping actions.
    private lateinit var itemTouchHelper: ItemTouchHelper

    /*  Do not modify this method.
     *
     *  Handles the initialization of the views and loading of data.
     */
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        binding.fabAddMedia.setOnClickListener {
            showCustomDialogue().show()
        }

        val playlistDatabase = PlaylistDatabase(applicationContext)
        playlistAdapter = PlaylistAdapter(playlistDatabase.getPlaylistMedia(), this)
        binding.playlist.layoutManager = LinearLayoutManager(applicationContext)
        binding.playlist.adapter = playlistAdapter

        val swipeCallback = SwipeCallback(0, ItemTouchHelper.LEFT or ItemTouchHelper.RIGHT)
        swipeCallback.playlistAdapter = playlistAdapter
        itemTouchHelper = ItemTouchHelper(swipeCallback)
        itemTouchHelper.attachToRecyclerView(binding.playlist)
    }

    /*  Only modify the portion where it requires
     *
     *  Creates a dialogue box that handles adding a media item to the DB. The user can input
     *  information in the fields provided.
     */
    private fun showCustomDialogue(): Dialog {
        return this?.let {
            val builder = AlertDialog.Builder(it)
            // The view binding instance of the dialogue box's layout
            val dialogueInsertMediaBinding : DialogueInsertMediaBinding = DialogueInsertMediaBinding.inflate(it.layoutInflater)

            with(builder){
                // Logic for insertion of a media item into the DB
                setPositiveButton("SAVE",
                    DialogInterface.OnClickListener { dialog, id ->
                        val playlistDatabase = PlaylistDatabase(applicationContext)
                        /*  TODO #1
                         *      Supply the logic to add a media item to the DB by using addMedia()
                         *      of the PlaylistDatabase.
                         *      Do not modify anything above this statement.
                         */
                        val title = dialogueInsertMediaBinding.mediaAddTitle.text.toString()
                        val duration = dialogueInsertMediaBinding.mediaAddDuration.text.toString()

                        // For the Spinner, you need to get the selected item's text
                        val type = dialogueInsertMediaBinding.mediaAddType.selectedItem.toString()


                        if (title.isNotEmpty() && type.isNotEmpty() && duration.isNotEmpty()) {
                            // 1. Create an item to be added to the database.
                            //    Use the secondary constructor which sets a default ID,
                            //    as the database will generate the actual ID.
                            val newMediaItemForDb = PlayListMediaItem(title = title, mediaType = type, mediaDuration = duration)

                            // 2. Add to database and get the generated ID
                            val newGeneratedMediaId = playlistDatabase.addMedia(newMediaItemForDb)

                            // 3. Create the item WITH the correct ID from the database to add to the adapter.
                            //    Use the PRIMARY constructor and the correct parameter name 'mediaId'.
                            val addedItemForAdapter = PlayListMediaItem(
                                mediaId = newGeneratedMediaId, // Use 'mediaId' here
                                title = title,
                                mediaType = type,
                                mediaDuration = duration
                            )
                            playlistAdapter.addPlayListMediaItem(addedItemForAdapter)
                            playlistAdapter.notifyItemInserted(playlistAdapter.itemCount - 1)
                        }
                        // Do not modify anything below this statement.
                        binding.playlist.smoothScrollToPosition(playlistAdapter.itemCount - 1)
                    })
                // If the user cancels, nothing happens.
                setNegativeButton("Cancel",
                    DialogInterface.OnClickListener { dialog, id ->

                    })
                setView(dialogueInsertMediaBinding.root)
                create()
            }
        } ?: throw IllegalStateException("Activity cannot be null")
    }
}