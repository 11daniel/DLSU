package com.mobdeve.a01_androidbasics

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.Button
import android.widget.EditText

/*  This walk through serves as an entry lesson to the basics of both Kotlin and Android
    development. However, discussion is kept high-level, particularly the usage of views.
 */

/* (1) The MainActivity serves as the entry point into application. It doesn't have to be called
       "MainActivity", but for this app, it is specified as the main. Check the AndroidManifest.xml
       for how this was specified. Most "Activity" classes inherit (or extends in Java) from the
       AppCompatActivity class. We won't discuss much about what an Activity is, so in the meantime,
       just think of it as a screen.
 */
class MainActivity : AppCompatActivity() {
    /* (2) A companion object is Kotlin's way of implementing static members of a class. The code
           inside is equivalent to the following Java code:
           public static final String TAG = "MainActivity";
     */
    companion object {
        const val TAG : String = "MainActivty"
    }

    /* (3) There are various constructs that correspond to UI Items such as:
                TextView - Equivalent to HTML's Label or Java Swing's JLabel
                EditView - Equivalent to HTML's TextField or Java Swing's JTextField
                Button - Equivalent to HTML's Button or Java Swing's JButton
           In Kotlin, we specify lateinit because we're initializing the variables later in the
           code. Kotlin is sensitive to variables nullable variables.
     */
    private lateinit var celField: EditText
    private lateinit var farField: EditText
    private lateinit var convertBtn: Button

    /*(4) Most screens of an app requires the use of an Activity. Each Activity has a different
          functions that are triggered based of the state of the activity. The first one is called
          the onCreate which is called upon the creation of the activity when the app is started.
          More on this will be discussed in the lecture on Activity Lifecycle.
     */
    override fun onCreate(savedInstanceState: Bundle?) {
        /* (5) When a "screen" is created, it must call the initialization data of its parent to
               start the process. It should also load an interface which is done by calling
               setContentView(). The activity to be loaded will be loaded from the R java resource
               class which is generated. Check the activity's layout found in res > layout.
         */
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        /* (6) UI items are typically referred to as Views. When Views are created in the layout and
               there is a need to use them, they should be "found" by referencing their ID. Using
               findViewById() is how we can "link" the instances created when the layout is inflated
               with our code.
               Note: This is actually an inefficient way of instantiation variables from the layout.
               There is a concept called "data binding", which is much more efficient manner of
               linking View instances. We'll discuss more on this in the topic of Views and Layouts.
         */
        this.celField = findViewById(R.id.celField)

        this.farField = findViewById(R.id.farField)

        /* (7) In Kotlin, getters and setters are not a common construct to use because each
               declared variable already comes with a default getter and setter. These concepts are
               abstracted from us to make the syntax simpler. In the example below, it seems like
               we're directly modifying the variable isEnabled, but Kotlin actually recognizes this
               as a set operation and sends the value through a setter. In this manner,
               encapsulation is still respected. There's much more to how this abstraction is
               performed, but we'll leave this topic here for now.
         */
        this.farField.isEnabled = false

        this.convertBtn = findViewById(R.id.convertBtn)

        /* (8) Similar to Swing, listeners are used to check if an action is made by the user.
               There are various kinds of listeners that exist. One of the most commonly used one is
               the OnClickListener which is used by the button.
         */
        this.convertBtn.setOnClickListener(View.OnClickListener {
            /* (9) Note that celField.text is an Editable object -- not a String. This is why we're
                   converting it to a String. Additionally, farField.text = far.toString() is not
                   used because far.toString() is... a String and farField.text is an Editable. We
                   would either have to convert far.toString() to an Editable object or use
                   farField.setText(), which accepts a String object that'll be assigned properly.
             */
            val far = convertCelToFar(celField.text.toString().toDouble())
            farField.setText(far.toString())

            /* (10) Log is used as a way for the application to talk to the Logcat. This is useful
                    for debugging an application. There are various kinds of logs. More info at:
                    https://developer.android.com/reference/android/util/Log
                    To view this log, open Logcat found in the bottom item bar of the IDE.
             */
            Log.d(TAG,"onClickListener of convertBtn finished execution")
        })

        /* TODO: Implement the logic for initializing the swap mechanism. For the swapping, we would
                 want to (1) enable the currently disabled field (which ever it may be), (2) disable
                 the originally enabled field, (3) modify the logic in the convertBtn to know which
                 conversion should take place.
                 Please note that you'll have to modify other parts of the code -- not just adding
                 at the end of this comment.
         */




        Log.d(TAG,"onCreate finished execution")
    }

    // Do not delete this function
    private fun convertCelToFar(celValue: Double): Double {
        return celValue * 9 / 5 + 32
    }

    /* TODO: Implement the logic for convertFarToCel() directly below this comment. The function
             should take in a double value representing the current Fahrenheit and outputs the
             equivalent Celsius value. Make sure to use the function you'll create.
     */



}