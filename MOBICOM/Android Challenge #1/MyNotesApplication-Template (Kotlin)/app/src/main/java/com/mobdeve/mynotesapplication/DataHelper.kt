package com.mobdeve.mynotesapplication

import android.content.Context

/*
 *      NOTE: You are not allowed to modify anything in this file.
 */
class DataHelper {
    companion object {
        /*
        *   Use this method to generate the data expected at start of the app. Remember, a companion
        *   object in Kotlin is like declaring an item to be static in Java.
        * */
        fun generateData() : ArrayList<NoteModel> {
            val data = ArrayList<NoteModel>()

            data.add(NoteModel("Shops in Robinsons Manila", "Adidas\nBench\nConverse\nCotton On\nCrocs\nDairy Queen\nFigaro Coffee\nForever 21\nH&M\nJollibee"))
            data.add(NoteModel("Grocery List", "[ ]Bread\n[x]Butter\n[ ]Chicken\n[x]Soda"))
            data.add(NoteModel("ChatGPT's A Walk in the Park", "Today, I took a leisurely walk in the park and it was the best decision I made all day. The sun was shining, the birds were chirping, and the flowers were in full bloom. It was a peaceful escape from the hustle and bustle of daily life. I strolled along the winding paths, taking in the natural beauty around me. I even stopped to watch a group of children playing on the swings and felt a sense of nostalgia for my own childhood. As I made my way back home, I felt refreshed and rejuvenated. It's amazing what a simple walk in the park can do for the soul."))
            data.add(NoteModel("ChatGPT's A Day of Productivity and Self-Care", "Today was a great day! I started off the morning feeling refreshed and energized, which is always a good sign. I made myself a delicious breakfast and sat down to write out my to-do list for the day.\n" +
                    "\nI tackled my work tasks first and managed to get a lot done. I felt productive and accomplished, which always gives me a sense of satisfaction. After finishing my work, I took a break to do some yoga and stretching. It felt great to move my body and clear my mind.\n" +
                    "\nFor lunch, I met up with a friend at a new cafe in town. We caught up on each other's lives and shared some laughs. It was nice to take a break from work and enjoy some good company.\n" +
                    "\nIn the afternoon, I did some self-care activities. I took a long bubble bath and read a book that I've been wanting to dive into. I also did a face mask and painted my nails. It's important to take care of yourself, and I felt so relaxed and rejuvenated afterwards.\n" +
                    "\nTo end the day, I cooked a delicious dinner and watched a movie. I felt fulfilled and content with how the day went. It's important to have days like these to recharge and focus on self-care.\n" +
                    "\nOverall, today was a great day. I hope tomorrow will be just as productive and fulfilling."))
            data.add(NoteModel("ChatGPT's A Busy Day", "Just wanted to drop a quick note to share about my day. It was a busy one! I had a lot of work to get done, and it seemed like the day just flew by.\n" +
                    "\nI managed to complete everything on my to-do list, though, so that was a relief. I even squeezed in a quick workout at the gym during my lunch break, which helped me feel more energized for the rest of the day.\n" +
                    "\nNow that the workday is over, I'm looking forward to some relaxation and downtime. Maybe I'll watch a movie or read a book. Whatever it is, I'm ready to unwind and recharge for tomorrow."))
            data.add(NoteModel("Lorem ipsum dolor sit amet", "consectetur adipiscing elit. Praesent non sem lacinia, vestibulum est et, posuere augue. In mollis posuere tristique. Integer felis tortor, varius vitae nibh blandit, tincidunt commodo eros. Nullam ac risus volutpat, egestas velit eu, aliquam lectus. Donec quis imperdiet tortor. Donec malesuada ex at blandit maximus. Aenean dapibus vehicula elit, eu porta ligula lacinia vel. Donec at nibh sit amet velit viverra maximus."))
            data.add(NoteModel("Vivamus urna nulla", "molestie eget rhoncus sit amet, pellentesque cursus dui. Integer sodales sem sagittis iaculis tincidunt. Nulla facilisi. Maecenas vitae tempus urna. Proin id metus ligula. Ut ac venenatis nibh. Aenean lacinia suscipit nisl vel suscipit. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Ut libero orci, volutpat ac posuere sit amet, egestas laoreet diam. Pellentesque sed ipsum purus. "))
            data.add(NoteModel("Donec sit amet mi commodo,", "ullamcorper lectus et, lobortis orci. Ut et erat ac arcu cursus pulvinar sed ac dolor. Maecenas erat urna, rutrum sit amet facilisis at, venenatis ac arcu. Sed tincidunt justo at ligula cursus consectetur et vitae urna. Sed a varius risus. In tempor sapien urna, non venenatis neque sodales sit amet. Vivamus tincidunt at ex convallis semper. Donec ut tempus ligula. Maecenas laoreet lorem ut consectetur hendrerit. "))
            data.add(NoteModel("Sed rutrum arcu ante", "mattis tincidunt odio interdum in. Sed fringilla nulla libero. Curabitur volutpat, risus posuere porttitor cursus, dui est ultricies libero, id ullamcorper nisl nulla mattis nisl. Duis non nisl sem. Nam purus nunc, feugiat ac quam non, consequat volutpat dui. Mauris hendrerit posuere tristique. Fusce bibendum neque enim, vitae maximus libero feugiat sit amet. Vestibulum vehicula diam nec ex tristique mollis. Aliquam eget accumsan turpis. In vel diam vehicula, eleifend ipsum et, aliquet metus. Fusce et nisl et felis dictum fringilla. Integer aliquet tellus augue, in hendrerit tellus congue commodo. Nam in ligula condimentum lacus molestie ultrices eu rhoncus orci. Phasellus tristique ex nec pulvinar egestas. Cras at sodales est. "))
            data.add(NoteModel("Anime Watchlist", "Berserk: Ougon Jidai-hen - Memorial Edition 6 / 13\n" +
                    "Boku no Hero Academia 6th Season 21 / 25\n" +
                    "Bungou Stray Dogs 4th Season 5 / 13\n" +
                    "Shingeki no Kyojin: The Final Season - Kanketsu-hen 1 / 2\n" +
                    "Tokyo Revengers: Seiya Kessen-hen 8 / 13 "))
            data.add(NoteModel("My Reflection (Draft)", "In the amazing book Moby Dick by the author Herman Melville, the author recounts his story of being at sea. In the first part of his book, the author, calling himself Ishmael, is in a small sea-side town and he is sharing a bed with a man named Queequeg"))

            return data
        }
    }

}