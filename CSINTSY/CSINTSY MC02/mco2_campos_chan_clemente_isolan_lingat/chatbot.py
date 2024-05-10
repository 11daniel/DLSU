# CSINTSY S12 Group 4 MCO2
# Authors: Campos, Chan, Clemente, Isolan, Lingat

from conversionToPROLOG import *
from pyswip import Prolog

# initializes the PROLOG object
prolog = Prolog()
# consults the group's knowledge base
prolog.consult("knowledge_base.pl")

print("\nWelcome to the Family Relationships Chatbot!\n")
print("Please input 'exit' if you want to stop the program.")

notYetDone = True

# Loops until the user inputs exit.
while(notYetDone):
    prompt = input("> ")

    # this checks for the last character in the input string to determine if query or new knowledge
    checker = prompt[-1]
    
    # sets the looping condition to false, eventually terminating the loop
    if prompt == "exit":
        notYetDone = False

    # checks if the given statement is an assertion
    elif checker == ".":
        prompt = convertToFactInProlog(prompt)

        # If the converting function returns an error due to an impossibility, it will not assert new information
        if prompt == "ERROR":
            print("That's impossible!")

        # If the converting function returns an array of strings containing assertions, it will assert them one by one
        elif isinstance(prompt, list):
            try:
                for fact in prompt:
                    prolog.assertz(fact)
                print("OK! I learned something.")
            except Exception as e:
                print("Error! Check your input.")

        # Otherwise, it will assert only one fact
        else:
            try:
                prolog.assertz(prompt)
                print("OK! I learned something.")
            except Exception as e:
                print("Error! Check your input.")

    # checks if the given statement is a question.
    elif checker == "?":
        try:
            prompt = convertToQueryInProlog(prompt)
            
            # Checks if the word "Who" is not in the prompt and if it is not, it executes the query that shows either Yes or No
            if "Who" not in prompt:
                query = list(prolog.query(prompt))
                if query:
                    print("Yes!")
                else:
                    print("No!")
            # This is to print the names of queries that involve multiple answers.
            else:
                query = prolog.query(prompt)
                for solution in query:
                    output = solution['Who']
                    name = output.capitalize()
                    print(name)

        except Exception as e:
            print("Error! Something happened. :(")