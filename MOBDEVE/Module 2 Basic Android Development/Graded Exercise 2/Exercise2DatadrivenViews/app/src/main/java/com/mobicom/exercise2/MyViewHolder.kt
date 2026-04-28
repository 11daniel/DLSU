package com.mobicom.exercise2

import android.view.View
import android.widget.Button
import android.widget.ImageView
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView

class MyViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {
    private val profilePicture: ImageView = itemView.findViewById<ImageView>(R.id.imageView)
    private val postImage: ImageView = itemView.findViewById<ImageView>(R.id.imageView2)
    private val likeButton: Button = itemView.findViewById<Button>(R.id.button)
    private val username: TextView = itemView.findViewById<TextView>(R.id.textView)
    private val location: TextView = itemView.findViewById<TextView>(R.id.textView2)
    private val username2: TextView = itemView.findViewById<TextView>(R.id.textView3)
    private val caption: TextView = itemView.findViewById<TextView>(R.id.textView4)
    private val datePosted: TextView = itemView.findViewById<TextView>(R.id.textView5)

    fun bindData(post: Post) {
        profilePicture.setImageResource(post.userImageId)
        postImage.setImageResource(post.imageId)
        likeButton.setBackgroundResource(if (post.liked) R.drawable.ic_favorite_filled else R.drawable.ic_favorite_border)
        username.text = post.username
        location.text = post.location ?: ""
        username2.text = post.username
        caption.text = post.caption ?: ""
        datePosted.text = post.datePosted
        likeButton.setOnClickListener {
            post.liked = !post.liked
            likeButton.setBackgroundResource(if (post.liked) R.drawable.ic_favorite_filled else R.drawable.ic_favorite_border)
        }
    }
}