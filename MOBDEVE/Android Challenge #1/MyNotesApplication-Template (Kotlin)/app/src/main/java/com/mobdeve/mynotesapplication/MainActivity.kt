package com.mobdeve.mynotesapplication

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import androidx.activity.result.ActivityResult
import androidx.activity.result.contract.ActivityResultContracts
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.mobdeve.mynotesapplication.databinding.ActivityMainBinding

// Daniel Gavrie Y. Clemente - S18

class MainActivity : AppCompatActivity() {
    // Do not remove these three variables
    private lateinit var data: ArrayList<NoteModel>         // Holds the data for the app
    private lateinit var myAdapter: MyAdapter               // Holds the adapter for the RecyclerView
    private lateinit var viewBinding: ActivityMainBinding   // Holds the views of the ActivityMainBinding
    private lateinit var recyclerView: RecyclerView

    /*
    *   TODO: Complete the viewNoteLauncher logic. The code below should handle making changes to the
    *       data ArrayList in case the "Save Changes" button was clicked. If none, then nothing should
    *       happen.
    * */
    private val viewNoteLauncher = registerForActivityResult(
        ActivityResultContracts.StartActivityForResult()) { result: ActivityResult ->
        if (result.resultCode == RESULT_OK) {
            val title = result.data!!.getStringExtra(ViewNoteActivity.titleKey)
            val body = result.data!!.getStringExtra(ViewNoteActivity.bodyKey)
            val position = result.data!!.getIntExtra(ViewNoteActivity.positionKey, -1)

            if(position != - 1 && title != null && body != null) {
                data[position].title = title
                data[position].body = body
                myAdapter.notifyItemChanged(position)
            }
        }
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        /*
        *   Please note that this application implementing ViewBinding. If you don't want to use
        *   ViewBinding, then please make sure to modify the buildFeatures attribute in the
        *   build.grade (app) to false and then modify the next two lines accordingly.
        * */
        this.viewBinding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(this.viewBinding.root)

        // This loads the note data into the data attribute.
        this.data = DataHelper.generateData()
//        val clickListener = View.OnClickListener {
//            val data = view.tag as NoteModel
//            val title = data.title
//            val body = data.body
//            val intent = Intent(applicationContext, ViewNoteActivity::class.java)
//            intent.putExtra("TITLE_KEY", title)
//            intent.putExtra("BODY_KEY", body)
//            this.startActivity(intent)
//        }

        this.myAdapter = MyAdapter(this.data, viewNoteLauncher)

        /*
        *   TODO: Provide the logic for setting up the RecyclerView.
        * */
        this.recyclerView = findViewById(R.id.recyclerView)
        this.recyclerView.adapter = myAdapter
        this.recyclerView.layoutManager = LinearLayoutManager(this)


    }
}