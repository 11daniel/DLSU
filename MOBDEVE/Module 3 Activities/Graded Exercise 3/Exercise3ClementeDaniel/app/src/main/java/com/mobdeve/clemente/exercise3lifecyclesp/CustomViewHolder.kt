package com.mobdeve.clemente.exercise3lifecyclesp

import android.view.View
import androidx.recyclerview.widget.RecyclerView

/*
 *      This is the super class for the two ViewHolders used in this application. This was done
 *      because MyAdapter can only have one ViewHolder type and I wanted to keep the ViewHolders
 *      separate from each other (in terms of their responsibility). All subclasses would need to
 *      have their own implementation of bindData, as well as certain things for the like button.
 * */
abstract class CustomViewHolder(itemView: View?) : RecyclerView.ViewHolder(itemView!!) {
    abstract fun bindData(post: PostModel?)
    abstract fun setLikeBtnOnClickListener(onClickListener: View.OnClickListener?)
    abstract fun setLikeBtnVisibility(value: Int)
}