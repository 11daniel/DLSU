// your package here
package com.example.PracticeFakedexProvideFiles.model  // Or whatever your package is


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
        return "PokemonModel{" +
                "name='" + name + '\'' +
                ", specie='" + specie + '\'' +
                ", location='" + location + '\'' +
                ", desc='" + desc + '\'' +
                ", imageId=" + imageId +
                '}'
    }
}