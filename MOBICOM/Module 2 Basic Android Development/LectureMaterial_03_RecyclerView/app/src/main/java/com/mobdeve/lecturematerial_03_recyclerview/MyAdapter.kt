package com.mobdeve.lecturematerial_03_recyclerview

import android.view.LayoutInflater
import android.view.ViewGroup
import android.widget.Toast
import androidx.recyclerview.widget.RecyclerView.Adapter


/*  An Adapter is the "middle man" that helps bind our data to the item view holder. Our Adapter
    extends the RecyclerView's Adapter class (an abstract class). We need to specify the generics
    tag so that it knows which ViewHolder to model after. Some walkthroughs integrate the custom
    ViewHolder into the Adapter class. In this walkthroughs, we create a separate file for the
    custom ViewHolder.

    The RecyclerView's Adapter class requires three methods to be implemented:
        onCreateViewHolder -> What happens when the ViewHolder is created
        onBindViewHolder -> What happens when binding data to the ViewHolder
        getItemCount -> The total data items
* */
class MyAdapter(private val data: ArrayList<Character>): Adapter<MyViewHolder>() {
    /*  onCreateViewHolder requires in two parameters:
            parent -> Which is the parent View where this adapter is associated with; this is
                      typically the RecyclerView
                      recall: recyclerView.adapter = MyAdapter(this.characterList)
            viewType -> This parameter refers to the
    * */
    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): MyViewHolder {
        // Create a LayoutInflater using the parent's (i.e. RecyclerView's) context
        val inflater = LayoutInflater.from(parent.context)
        // Inflate a new View given the item_layout.xml item view we created.
        val view = inflater.inflate(R.layout.item_layout, parent, false)
        // Return a new instance of our MyViewHolder passing the View object we created

        return MyViewHolder(view)
    }

    /*  Whenever the RecyclerView feels the need to bind data, onBindViewHolder is called. Here, we
        gain access to the specific ViewHolder instance and the position in our data that we should
        be binding to the view.
    * */
    override fun onBindViewHolder(holder: MyViewHolder, position: Int) {
        // Please note that bindData is a function we created to adhere to encapsulation. There are
        // many ways to implement the binding of data.
        holder.bindData(data.get(position))

        holder.itemView.setOnClickListener {
            Toast.makeText(holder.itemView.context, "Character selected: " +
                    data[holder.adapterPosition].name, Toast.LENGTH_SHORT).show()
        }
    }

    override fun getItemCount(): Int {
        // This needs to be modified, so don't forget to add this in.
        return data.size
    }
}