package com.mobdeve.lecturematerial_03_recyclerview.fakeadex.viewholders

import android.view.View
import androidx.recyclerview.widget.RecyclerView
import com.mobdeve.lecturematerial_03_recyclerview.databinding.ItemPokemonLayoutBinding
import com.mobdeve.lecturematerial_03_recyclerview.fakeadex.models.PokemonModel

class FakeadexViewHolder(private val viewBinding: ItemPokemonLayoutBinding): RecyclerView.ViewHolder(viewBinding.root) {

        fun bindData(model: PokemonModel) {
            this.viewBinding.txtFakeadexName.text = model.name
            this.viewBinding.txtFakeadexDesc.text = model.desc
            this.viewBinding.txtFakeadexLocationValue.text = model.location
            this.viewBinding.txtFakeadexSpeciesValue.text = model.specie
            this.viewBinding.imgFakeadexPicture.setImageResource(model.imageId)
        }

    fun setDeleteOnClickListener(onClickListener: View.OnClickListener) {
        this.viewBinding.btnFakeadexDelete.setOnClickListener(onClickListener)
    }
}
