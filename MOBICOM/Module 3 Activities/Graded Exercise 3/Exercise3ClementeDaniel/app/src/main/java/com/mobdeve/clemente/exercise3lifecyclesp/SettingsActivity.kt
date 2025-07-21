package com.mobdeve.clemente.exercise3lifecyclesp

import android.content.SharedPreferences
import android.os.Bundle
import android.widget.Switch
import androidx.appcompat.app.AppCompatActivity

class SettingsActivity : AppCompatActivity() {
    // Views for the switches
    private lateinit var linearViewSwitch: Switch
    private lateinit var hideLikeSwitch: Switch

    private lateinit var prefs: SharedPreferences

    // Indicators for what Layout should be used or if the like buttons should be hidden
    private val viewSelected = LayoutType.LINEAR_VIEW_TYPE.ordinal // int of LayoutType.LINEAR_VIEW_TYPE (default) or LayoutType.GRID_VIEW_TYPE
    private val hideLikeSelected = false // true -> hidden buttons; false -> shown buttons (default)

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_settings)

        this.prefs = getSharedPreferences("Exercise3LifecycleSP", MODE_PRIVATE)

        // Instantiation of the Switch views
        this.linearViewSwitch = findViewById(R.id.viewSwitch)
        this.hideLikeSwitch = findViewById(R.id.hideLikeSwitch)

        this.linearViewSwitch.isChecked = returnBoolean(this.prefs.getInt("viewSelected", this.viewSelected))
        this.hideLikeSwitch.isChecked = this.prefs.getBoolean("hideLikeSelected", this.hideLikeSelected)

        this.linearViewSwitch.setOnClickListener {
            this.prefs.edit().putInt("viewSelected", returnInt(this.linearViewSwitch.isChecked)).apply()
        }

        this.hideLikeSwitch.setOnClickListener {
            this.prefs.edit().putBoolean("hideLikeSelected", this.hideLikeSwitch.isChecked).apply()
        }
    }

    /*
     * Method to map an integer to the appropriate boolean value based on the given LayoutType.
     * */
    private fun returnBoolean(value: Int): Boolean {
        if (value == LayoutType.LINEAR_VIEW_TYPE.ordinal)
            return true
        else
            return false
    }

    /*
     * Method to map a boolean value (representing whether the linearViewSwitch is checked or not)
     * to appropriate LayoutType in ordinal representation.
     * */
    private fun returnInt(value: Boolean): Int {
        if (value == true)
            return LayoutType.LINEAR_VIEW_TYPE.ordinal
        else
            return LayoutType.GRID_VIEW_TYPE.ordinal
    }
}