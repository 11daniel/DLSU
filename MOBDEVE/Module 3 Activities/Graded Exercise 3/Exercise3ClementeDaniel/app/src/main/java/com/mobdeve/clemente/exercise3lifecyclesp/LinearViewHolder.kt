package com.mobdeve.clemente.exercise3lifecyclesp

import android.view.View
import android.widget.ImageButton
import android.widget.ImageView
import android.widget.LinearLayout
import android.widget.TextView

class LinearViewHolder(itemView: View) : CustomViewHolder(itemView) {
    private val headerUsernameTv: TextView = itemView.findViewById(R.id.headerUsernameTv)
    private val captionUsernameTv: TextView = itemView.findViewById(R.id.captionUsernameTv)
    private val captionTv: TextView = itemView.findViewById(R.id.captionTv)
    private val datePostedTv: TextView = itemView.findViewById(R.id.dateTv)
    private val locationTv: TextView = itemView.findViewById(R.id.locationTv)
    private val captionHll: LinearLayout = itemView.findViewById(R.id.captionHll)
    private val accountImageIv: ImageView = itemView.findViewById(R.id.accountImageIv)
    private val postImageIv: ImageView = itemView.findViewById(R.id.postImageIv)
    private val likeIbtn: ImageButton = itemView.findViewById(R.id.gridLikeIbtn)

    override fun bindData(post: PostModel?) {
        this.headerUsernameTv.text = post!!.username
        this.captionUsernameTv.text = post.username
        this.datePostedTv.text = post.datePosted
        this.accountImageIv.setImageResource(post.userImageId)
        this.postImageIv.setImageResource(post.imageId)

        if (post.caption == null) {
            this.captionHll.visibility = LinearLayout.GONE
        } else {
            this.captionTv.text = post.caption
        }
        if (post.location == null) {
            this.locationTv.visibility = View.GONE
        } else {
            this.locationTv.text = post.location
        }
        if (post.liked) {
            this.likeIbtn.setImageResource(R.drawable.ic_like_on_foreground)
        } else {
            this.likeIbtn.setImageResource(R.drawable.ic_like_off_foreground)
        }
    }

    override fun setLikeBtnOnClickListener(onClickListener: View.OnClickListener?) {
        likeIbtn.setOnClickListener(onClickListener)
    }

    override fun setLikeBtnVisibility(value: Int) {
        likeIbtn.visibility = value
    }
}