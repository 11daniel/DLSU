package com.mobdeve.lecturematerial_03_recyclerview.fakeadex.adapters

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Toast
import androidx.recyclerview.widget.RecyclerView
import com.mobdeve.lecturematerial_03_recyclerview.MyViewHolder
import com.mobdeve.lecturematerial_03_recyclerview.R
import com.mobdeve.lecturematerial_03_recyclerview.databinding.ItemPokemonLayoutBinding
import com.mobdeve.lecturematerial_03_recyclerview.fakeadex.models.PokemonModel
import com.mobdeve.lecturematerial_03_recyclerview.fakeadex.viewholders.FakeadexViewHolder

class FakeadexAdapter(private val data: ArrayList<PokemonModel>): RecyclerView.Adapter<FakeadexViewHolder>() {
    /*  onCreateViewHolder requires in two parameters:
            parent -> Which is the parent View where this adapter is associated with; this is
                      typically the RecyclerView
                      recall: recyclerView.adapter = MyAdapter(this.characterList)
            viewType -> This parameter refers to the
    * */
    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): FakeadexViewHolder {
        // Create a LayoutInflater using the parent's (i.e. RecyclerView's) context
        //val inflater = LayoutInflater.from(parent.context)
        // Inflate a new View given the item_layout.xml item view we created.
        //val view = inflater.inflate(R.layout.item_pokemon_layout, parent, false)
        // Return a new instance of our MyViewHolder passing the View object we created

        val itemViewBinding: ItemPokemonLayoutBinding = ItemPokemonLayoutBinding.inflate(LayoutInflater.from(parent.context), parent, false)
        return FakeadexViewHolder(itemViewBinding)
    }

    /*  Whenever the RecyclerView feels the need to bind data, onBindViewHolder is called. Here, we
        gain access to the specific ViewHolder instance and the position in our data that we should
        be binding to the view.
    * */
    override fun onBindViewHolder(holder: FakeadexViewHolder, position: Int) {
        // Please note that bindData is a function we created to adhere to encapsulation. There are
        // many ways to implement the binding of data.
        holder.bindData(this.data.get(position))

        holder.setDeleteOnClickListener(View.OnClickListener {
            holder.itemView.setOnClickListener {
                Toast.makeText(holder.itemView.context, "Pokemon deleted: " +
                        data[holder.adapterPosition].name, Toast.LENGTH_SHORT).show()
            }

            this.data.removeAt(position)
            notifyDataSetChanged()
        })
    }

    override fun getItemCount(): Int {
        // This needs to be modified, so don't forget to add this in.
        return data.size
    }
}