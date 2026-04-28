package com.mobdeve.lecturematerial_03_recyclerview.fakeadex.activities

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.PagerSnapHelper
import androidx.recyclerview.widget.RecyclerView
import androidx.recyclerview.widget.SnapHelper
import com.mobdeve.lecturematerial_03_recyclerview.Character
import com.mobdeve.lecturematerial_03_recyclerview.DataGenerator
import com.mobdeve.lecturematerial_03_recyclerview.MyAdapter
import com.mobdeve.lecturematerial_03_recyclerview.R
import com.mobdeve.lecturematerial_03_recyclerview.fakeadex.adapters.FakeadexAdapter
import com.mobdeve.lecturematerial_03_recyclerview.fakeadex.models.PokemonModel

class FakeadexActivity : AppCompatActivity() {
    // Our data
    private val pokemonList: ArrayList<PokemonModel> = com.mobdeve.lecturematerial_03_recyclerview.fakeadex.constants.DataGenerator.loadData()
    // Our RecyclerView reference
    private lateinit var recyclerView: RecyclerView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_fakeadex)

        // Initialize the RecyclerView
        this.recyclerView = findViewById(R.id.rvw_fake_pokedex)

        // Set the Adapter. We have to define our own Adapter so that we can properly set the
        // information into the item layout we created. It is typical to pass the data we want
        // displayed into the adapter. There are other variants of RecyclerViews that query data
        // from online sources in batches (instead of passing everything), but we'll get to that
        // when we reach accessing remote DBs.
        this.recyclerView.adapter = FakeadexAdapter(this.pokemonList)

        // Set the LayoutManager. This can be set to different kinds of LayoutManagers but we're
        // keeping things simple with a LinearLayout.
        var layoutManager = LinearLayoutManager(this)
        layoutManager.orientation = LinearLayoutManager.HORIZONTAL
        this.recyclerView.layoutManager = layoutManager

        val snapHelper: SnapHelper = PagerSnapHelper()
        snapHelper.attachToRecyclerView(this.recyclerView)
    }
}