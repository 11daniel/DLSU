package com.mobicom.s18.valdellon.derrick.exercise1

import android.os.Bundle
import android.widget.ImageButton
import androidx.activity.ComponentActivity

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.main_activity)
        var isFavorite = false

        val favButton = findViewById<ImageButton>(R.id.favButton)
        favButton.setOnClickListener {
            isFavorite = !isFavorite
            val icon = if (isFavorite) R.drawable.ic_favorite_filled else R.drawable.ic_favorite_border
            favButton.setImageResource(icon)
        }
    }
}

