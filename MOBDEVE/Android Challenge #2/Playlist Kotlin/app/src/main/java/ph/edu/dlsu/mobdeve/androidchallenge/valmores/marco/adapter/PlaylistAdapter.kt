package ph.edu.dlsu.mobdeve.androidchallenge.valmores.marco.adapter

import android.app.Activity
import android.app.AlertDialog
import android.app.Dialog
import android.content.DialogInterface
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.recyclerview.widget.RecyclerView
import ph.edu.dlsu.mobdeve.androidchallenge.valmores.marco.R
import ph.edu.dlsu.mobdeve.androidchallenge.valmores.marco.database.PlaylistDatabase
import ph.edu.dlsu.mobdeve.androidchallenge.valmores.marco.databinding.DialogueInsertMediaBinding
import ph.edu.dlsu.mobdeve.androidchallenge.valmores.marco.databinding.ItemMediaBinding
import ph.edu.dlsu.mobdeve.androidchallenge.valmores.marco.model.PlayListMediaItem

/*  Do not modify any declared variables and methods included in this class.
 *
 *  The PlaylistAdapter is a custom RecyclerView Adapter class.
 */
class PlaylistAdapter(private var playlistMediaItems: ArrayList<PlayListMediaItem>, private var activity: Activity): RecyclerView.Adapter<PlaylistAdapter.PlaylistViewHolder>(){

    // Handles the logic needed for getItemCount().
    override fun getItemCount(): Int {
        return this.playlistMediaItems.size
    }

    // Note: This method uses ViewBinding instead of inflating the ViewGroup.
    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): PlaylistAdapter.PlaylistViewHolder {
        val itemBinding = ItemMediaBinding.inflate(LayoutInflater.from(parent.context), parent, false)
        return PlaylistViewHolder(itemBinding)
    }


    // Handles binding a model to the ViewHolder.
    override fun onBindViewHolder(holder: PlaylistAdapter.PlaylistViewHolder, position: Int) {
        holder.bindPlayListMediaItem(this.playlistMediaItems[position], position)
    }

    /*  Handles adding a media item to the stored array list + updates the UI accordingly.
     *  Note: When a media item is added, it is added at the end of the RecyclerView.
     */
    fun addPlayListMediaItem(playListMediaItem: PlayListMediaItem) {
        this.playlistMediaItems.add(playListMediaItem)
        notifyItemInserted(this.playlistMediaItems.size - 1)
    }

    /*  Handles removing a media item from both the array list and the database. UI is updated
     *  accordingly.
     */
    fun removePlayListMediaItem(position: Int) {
        val playlistDatabase = PlaylistDatabase(activity.applicationContext)
        val mediaItem = playlistMediaItems[position]
        playlistDatabase.deleteMedia(mediaItem)

        playlistMediaItems.removeAt(position)
        notifyItemRemoved(position)
    }

    //  Handles updating a media item in the array list + updates the UI accordingly.
    fun updatePlayListMediaItem(position: Int, playListMediaItem: PlayListMediaItem) {
        playlistMediaItems[position] = playListMediaItem
        notifyItemChanged(position)
    }

    /*  Do not modify all declared variables and methods included in this class.
     *  PlaylistViewHolder is an inner class of PlaylistAdapter responsible for handling the logic
     *  of the ViewHolder. Please note that the class is also an OnClickListener.
     */
    inner class PlaylistViewHolder(private val itemBinding: ItemMediaBinding): RecyclerView.ViewHolder(itemBinding.root), View.OnClickListener {
        // To keep track of the position of the ViewHolder in the RecyclerView
        private var myPosition: Int = -1
        // To keep track of the media instance bound to the ViewHolder
        private lateinit var item: PlayListMediaItem

        // Allows for the itemView to trigger the logic in OnClick()
        init {
            this@PlaylistViewHolder.itemView.setOnClickListener(this)
        }

        /*  Handles binding a media item to the ViewHolder. The position of the ViewHolder is also
         *  included for the sake of knowing where to update in the array list.
         */
        fun bindPlayListMediaItem(playListMediaItem: PlayListMediaItem, position: Int) {
            this@PlaylistViewHolder.myPosition = position
            this@PlaylistViewHolder.item = playListMediaItem

            with(itemBinding) {
                mediaTitle.text = "${playListMediaItem.mediaId} - ${playListMediaItem.title}"
                mediaType.text = playListMediaItem.mediaType
                mediaDuration.text = playListMediaItem.mediaDuration

                when {
                    playListMediaItem.mediaType.equals("VIDEO", true) -> {
                        imageMedia.setImageResource(R.drawable.video_placeholder)
                    }
                    playListMediaItem.mediaType.equals("AUDIO", true) -> {
                        imageMedia.setImageResource(R.drawable.music_placeholder)
                    }
                }
            }
        }

        /*  When the itemView is clicked on, a custom dialogue will be shown. See
         *  showCustomDialogue()for more details.
         */
        override fun onClick(v: View?) {
            showCustomDialogue().show()
        }

        /*  Shows a custom dialogue that helps with (1) showing the encoded information of a media
         *  item, (2) allowing the user to modify parts of the item, and (3) perform an update.
         */
        private fun showCustomDialogue(): Dialog {
            return activity?.let {
                val builder = AlertDialog.Builder(it)
                val dialogueInsertMediaBinding : DialogueInsertMediaBinding =
                    DialogueInsertMediaBinding.inflate(it.layoutInflater)

                with(dialogueInsertMediaBinding) {
                    mediaAddTitle.setText(item.title)
                    mediaAddDuration.setText(item.mediaDuration)

                    if(item.mediaType.equals("VIDEO", true)) {
                        mediaAddType.setSelection(0, true)
                    } else {
                        mediaAddType.setSelection(1, true)
                    }

                }

                with(builder) {
                    /*  If the user presses update, the encoded information is updated in the
                     *  array list (via updatePlayListMediaItem()) and in the DB (via
                     *  playlistDatabase.updateMedia().
                     */
                    setPositiveButton("UPDATE",
                        DialogInterface.OnClickListener { dialog, id ->
                            val playlistDatabase = PlaylistDatabase(activity.applicationContext)

                            var mediaItem = PlayListMediaItem().apply {
                                mediaId = item.mediaId
                                title = dialogueInsertMediaBinding.mediaAddTitle.text.toString()
                                mediaType = dialogueInsertMediaBinding.mediaAddType.selectedItem.toString()
                                mediaDuration = dialogueInsertMediaBinding.mediaAddDuration.text.toString()
                            }

                            playlistDatabase.updateMedia(mediaItem)
                            updatePlayListMediaItem(myPosition, mediaItem)
                        })
                    // If the user presses cancel, nothing happens.
                    setNegativeButton("Cancel",
                        DialogInterface.OnClickListener { dialog, id ->

                        })
                    setView(dialogueInsertMediaBinding.root)
                    create()
                }
            } ?: throw IllegalStateException("Activity cannot be null")
        }

    }
}