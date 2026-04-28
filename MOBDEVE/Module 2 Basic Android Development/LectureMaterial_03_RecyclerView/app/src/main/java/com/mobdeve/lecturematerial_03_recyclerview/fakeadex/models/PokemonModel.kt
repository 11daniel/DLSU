package com.mobdeve.lecturematerial_03_recyclerview.fakeadex.models// your package here

class PokemonModel(name: String, specie: String, location: String, desc: String, imageId: Int) {
    var name = name
        private set
    var specie = specie
        private set
    var location = location
        private set
    var desc = desc
        private set
    var imageId = imageId
        private set

    override fun toString(): String {
        return "com.mobdeve.lecturematerial_03_recyclerview.fakeadex.models.PokemonModel{" +
                "name='" + name + '\'' +
                ", specie='" + specie + '\'' +
                ", location='" + location + '\'' +
                ", desc='" + desc + '\'' +
                ", imageId=" + imageId +
                '}'
    }
}