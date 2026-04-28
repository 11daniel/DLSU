package com.mobdeve.mynotesapplication

import android.view.View
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView.ViewHolder
import com.mobdeve.mynotesapplication.databinding.ItemLayoutBinding

// Daniel Gavrie Y. Clemente - S18

/*
*   TODO: Make sure to specify the parameters needed by the ViewHolder super class. These are not
*       specified here because you can either use the ViewBinding instance of the item or the actual
*       instance of the itemView.
* */
class MyViewHolder(itemView: View) : ViewHolder(itemView) {
    /*
    *   bindData() takes a single NoteModel instance and binds its data to the views in the
    *       ViewHolder. You can remove this in favor of implementing setters, but a single method
    *       is cleaner.
    * */
    private val titleView: TextView = itemView.findViewById(R.id.itemTitle)
    private val bodyView: TextView = itemView.findViewById(R.id.itemBody)

    // this is for the recycler view in displaying previews of the notes

    fun bindData(noteData : NoteModel) {
        titleView.text = noteData.title // Assign to the edit text for the title
        bodyView.text = noteData.body.replace("\n", " ") // Assign to the edit text for the body
        // Note: Do not replace the .replace() method as this strips the new line character
    }
}