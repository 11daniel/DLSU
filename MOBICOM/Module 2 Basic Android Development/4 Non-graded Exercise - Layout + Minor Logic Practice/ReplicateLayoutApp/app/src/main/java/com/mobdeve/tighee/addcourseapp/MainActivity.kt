package com.mobdeve.tighee.addcourseapp

import android.os.Bundle
import android.view.View
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import com.google.android.material.floatingactionbutton.FloatingActionButton
import com.mobdeve.tighee.addcourseapp.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        val viewBinding: ActivityMainBinding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(viewBinding.root)

        viewBinding.firstAddBtn.setOnClickListener(View.OnClickListener {
            Toast.makeText(
                applicationContext,
                "Adding S15...",
                Toast.LENGTH_SHORT
            ).show()
        })

        viewBinding.firstAddBtn.setOnClickListener(View.OnClickListener {
            Toast.makeText(
                applicationContext,
                "Adding S16...",
                Toast.LENGTH_SHORT
            ).show()
        })
    }
}