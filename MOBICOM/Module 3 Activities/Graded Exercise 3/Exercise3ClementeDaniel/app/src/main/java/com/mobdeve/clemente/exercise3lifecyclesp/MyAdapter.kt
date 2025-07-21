package com.mobdeve.clemente.exercise3lifecyclesp

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageButton
import androidx.recyclerview.widget.RecyclerView

class MyAdapter(private val data: ArrayList<PostModel>) : RecyclerView.Adapter<CustomViewHolder>() {
    /* Variables to keep track of the current apps settings. Each variable has a setter and these
     * values must be set or else the Adapter will not be able to... adapt... appropriately.
     * */
    private var hideLikeBtn: Boolean? = null
    private var viewType = 0

    fun setViewType(viewType: Int) {
        this.viewType = viewType
    }

    fun setHideLikeBtn(value: Boolean?) {
        hideLikeBtn = value
    }

    /*
     * We override this method of the Adapter to return the appropriate layout ID based on the
     * viewType currently set. See onCreateViewHolder for intuition.
     * */
    override fun getItemViewType(position: Int): Int {
        if (viewType == LayoutType.LINEAR_VIEW_TYPE.ordinal)
            return R.layout.item_linear_layout
        else
            return R.layout.item_grid_format
    }

    /*
     * The viewType in the method's parameter corresponds with the value returned by
     * getItemViewType; hence, why we modified getItemViewType to return the layout ID. The layout
     * ID is returned so it's easier to plug into the layoutInflater.inflate method call. Otherwise,
     * we'd need a switch or if+else statement to determine which layout to use. Layout IDs (or
     * view IDs in general) are unique and won't overlap; hence, why this is alright to do.
     * */
    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): CustomViewHolder {
        // Inflate the appropriate layout based on the viewType returned and generate the itemView.
        val layoutInflater = LayoutInflater.from(parent.context)
        val itemView = layoutInflater.inflate(viewType, parent, false)

        // Determine which subclass of CustomViewHolder to generate based on the viewType
        val holder: CustomViewHolder
        if (viewType == R.layout.item_linear_layout)
            holder = LinearViewHolder(itemView)
        else
            holder = GridViewHolder(itemView)

        // Set the like button logic here
        holder.setLikeBtnOnClickListener { view ->
            if (data[holder.adapterPosition].liked) {
                (view as ImageButton).setImageResource(R.drawable.ic_like_off_foreground)
                data[holder.adapterPosition].liked = false
            } else {
                (view as ImageButton).setImageResource(R.drawable.ic_like_on_foreground)
                data[holder.adapterPosition].liked = true
            }
        }

        // Hide or display the like button (regardless of viewType) based on hideLikeBtn
        if (hideLikeBtn!!)
            holder.setLikeBtnVisibility(View.GONE)
        else
            holder.setLikeBtnVisibility(View.VISIBLE)
        return holder
    }

    /*
     * Utilize the bindData method all CustomViewHolders should have and pass actual binding logic
     * to the ViewHolders depending on what they are.
     * */
    override fun onBindViewHolder(holder: CustomViewHolder, position: Int) {
        holder.bindData(data[position])
    }

    /*
     * You thought it was a comment, but no!! It's me, DIO!
     * */
    override fun getItemCount(): Int {
        return data.size
    }
}