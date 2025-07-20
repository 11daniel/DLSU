package com.mobicom.exercise2

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.tooling.preview.Preview
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.mobicom.exercise2.ui.theme.Exercise2DatadrivenViewsTheme

class MainActivity : ComponentActivity() {

    private lateinit var data: ArrayList<Post>
    private lateinit var myAdapter: MyAdapter
    private lateinit var recyclerView: RecyclerView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        this.data = DataHelper.initializeData()
        this.myAdapter = MyAdapter(this.data)

        this.recyclerView = findViewById(R.id.recyclerView1)
        this.recyclerView.adapter = this.myAdapter
        this.recyclerView.layoutManager = LinearLayoutManager(this)


    }
}

