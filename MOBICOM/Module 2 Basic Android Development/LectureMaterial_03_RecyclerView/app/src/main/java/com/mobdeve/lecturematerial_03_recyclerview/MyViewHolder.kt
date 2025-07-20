package com.mobdeve.lecturematerial_03_recyclerview

import android.view.View
import android.widget.ImageView
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView.ViewHolder

/*  This is our custom ViewHolder class. Please note that the primary constructor of RecyclerView's
    ViewHolder requires an itemView to be passed (think of this as a super class constructor call).
    So we need to make sure we access that too. This class is usually instantiated in the
    onCreateViewHolder of the Adapter.
* */

class MyViewHolder(itemView: View): ViewHolder(itemView) {
    // In our item layout, we need two references -- an ImageView and a TextView. Please note that
    // the itemView is the RecyclerView -- which has context that we can use to find View instances.
    private val iv: ImageView = itemView.findViewById(R.id.characterImageIv)
    private val tv: TextView = itemView.findViewById(R.id.characterNameTv)

    // This is our own method that accepts a Character object and sets our views' info accordingly.
    fun bindData(character: Character) {
        iv.setImageResource(character.imageId)
        tv.text = character.name
    }
}