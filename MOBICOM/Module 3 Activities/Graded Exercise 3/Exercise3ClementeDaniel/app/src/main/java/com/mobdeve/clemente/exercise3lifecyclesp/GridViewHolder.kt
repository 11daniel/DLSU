package com.mobdeve.clemente.exercise3lifecyclesp

import android.view.View
import android.widget.ImageView

class GridViewHolder(itemView: View) : CustomViewHolder(itemView) {
    private val gridPostImageIv: ImageView = itemView.findViewById(R.id.gridPostImageIv)
    private val gridLikeIbtn: ImageView = itemView.findViewById(R.id.gridLikeIbtn)

    override fun bindData(post: PostModel?) {
        this.gridPostImageIv.setImageResource(post!!.imageId)
        if (post.liked) {
            this.gridLikeIbtn.setImageResource(R.drawable.ic_like_on_foreground)
        } else {
            this.gridLikeIbtn.setImageResource(R.drawable.ic_like_off_foreground)
        }
    }

    override fun setLikeBtnOnClickListener(onClickListener: View.OnClickListener?) {
        this.gridLikeIbtn.setOnClickListener(onClickListener)
    }

    override fun setLikeBtnVisibility(value: Int) {
        this.gridLikeIbtn.visibility = value
    }
}