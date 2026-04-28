package com.mobdeve.lecturematerial_03_recyclerview

/*  This class simply generates data needed for our project. Imagine we're pulling from a database
    somewhere. This just simplifies the process.
* */
class DataGenerator {
    companion object{
        fun generateData(): ArrayList<Character> {
            var tempList = ArrayList<Character>()
            tempList.add(Character(R.drawable.guts, "Guts"))
            tempList.add(Character(R.drawable.griffith, "Griffith"))
            tempList.add(Character(R.drawable.casca, "Casca"))
            tempList.add(Character(R.drawable.judeau, "Judeau"))
            tempList.add(Character(R.drawable.corkus, "Corkus"))
            tempList.add(Character(R.drawable.rickert, "Rickert"))
            tempList.add(Character(R.drawable.pippin, "Pippin"))
            tempList.add(Character(R.drawable.puck, "Puck"))
            tempList.add(Character(R.drawable.isidro, "Isidro"))
            tempList.add(Character(R.drawable.farnese, "Farnese"))
            tempList.add(Character(R.drawable.serpico, "Serpico"))
            tempList.add(Character(R.drawable.schierke, "Schierke"))
            return tempList
        }
    }
}