# This function converts the first letter of a name to lowercase because PROLOG constants demand all lowercase
def convertToLowerCase(name):
    first_word = name[0]
    return name.replace(first_word,first_word.lower(),1)

# Converts an assertion into its PROLOG equivalent
def convertToFactInProlog(input):
    # The following comments hold true for the rest of the functions inside this file
    if "siblings" in input:
        words = input.split() # Split the whole sentence word by word

        # Converts the first letter of a name to lowercase
        name1 = words[0]
        name1 = convertToLowerCase(name1)
        # Converts the first letter of a name to lower case

        name2 = words[2]
        name2 = convertToLowerCase(name2)

        # Returns the PROLOG equivalent
        if name1 == name2:
            return "ERROR"
        else:
            return "siblings({},{})".format(name1,name2)
    
    if "female" in input:
        words = input.split()
        name = words[0]
        name = convertToLowerCase(name)
        return "female({})".format(name)
    
    if "male" in input:
        words = input.split()
        name = words[0]
        name = convertToLowerCase(name)
        return "male({})".format(name)
    
    if "sister" in input:
        words = input.split()
        name1 = words[0]
        name1 = convertToLowerCase(name1)
        name2 = words[5]
        name2 = convertToLowerCase(name2).rstrip(name2[-1])

        if name1 == name2:
            return "ERROR"
        else:
            return "sister({},{})".format(name1,name2)
    
    if "brother" in input:
        words = input.split()
        name1 = words[0]
        name1 = convertToLowerCase(name1)
        name2 = words[5]
        name2 = convertToLowerCase(name2).rstrip(name2[-1])

        if name1 == name2:
            return "ERROR"
        else:
            return "brother({},{})".format(name1,name2)
    
    if "grandfather" in input:
        words = input.split()
        name1 = words[0]
        name1 = convertToLowerCase(name1)
        name2 = words[5]
        name2 = convertToLowerCase(name2).rstrip(name2[-1])

        if name1 == name2:
            return "ERROR"
        else:
            return "grandfather({},{})".format(name1,name2)
    
    if "father" in input:
        words = input.split()
        name1 = words[0]
        name1 = convertToLowerCase(name1)
        name2 = words[5]
        name2 = convertToLowerCase(name2).rstrip(name2[-1])

        if name1 == name2:
            return "ERROR"
        else:
            return "father({},{})".format(name1,name2)

    if "grandmother" in input:
        words = input.split()
        name1 = words[0]
        name1 = convertToLowerCase(name1)
        name2 = words[5]
        name2 = convertToLowerCase(name2).rstrip(name2[-1])

        if name1 == name2:
            return "ERROR"
        else:
            return "grandmother({},{})".format(name1,name2)
    
    if "mother" in input:
        words = input.split()
        name1 = words[0]
        name1 = convertToLowerCase(name1)
        name2 = words[5]
        name2 = convertToLowerCase(name2).rstrip(name2[-1])

        if name1 == name2:
            return "ERROR"
        else:
            return "mother({},{})".format(name1,name2)
        
    if "children" in input:
        words = input.split()
        results = [""]
        name1 = words[0]
        name1 = convertToLowerCase(name1).rstrip(name1[-1])
        name2 = words[1]
        name2 = convertToLowerCase(name2)
        name3 = words[3]
        name3 = convertToLowerCase(name3)
        name4 = words[-1]
        name4 = convertToLowerCase(name4).rstrip(name4[-1])
    
        if(name1 == name2):
            return "ERROR"
        elif(name1 == name3):
            return "ERROR"
        elif(name1 == name4):
            return "ERROR"
        elif(name2 == name3):
            return "ERROR"
        elif(name2 == name4):
            return "ERROR"
        elif(name3 == name4):
            return "ERROR"
        else:
            results.remove("")
            results.append("child({},{})".format(name1,name4))
            results.append("child({},{})".format(name2,name4))
            results.append("child({},{})".format(name3,name4))
            return results


    if "child" in input:
        words = input.split()
        name1 = words[0]
        name1 = convertToLowerCase(name1)
        name2 = words[5]
        name2 = convertToLowerCase(name2).rstrip(name2[-1])

        if name1 == name2:
            return "ERROR"
        else:
            return "child({},{})".format(name1,name2)
    
    if "daughter" in input:
        words = input.split()
        name1 = words[0]
        name1 = convertToLowerCase(name1)
        name2 = words[5]
        name2 = convertToLowerCase(name2).rstrip(name2[-1])

        if name1 == name2:
            return "ERROR"
        else:
            return "daughter({},{})".format(name1,name2)

    if "son" in input:
        words = input.split()
        name1 = words[0]
        name1 = convertToLowerCase(name1)
        name2 = words[5]
        name2 = convertToLowerCase(name2).rstrip(name2[-1])

        if name1 == name2:
            return "ERROR"
        else:
            return "son({},{})".format(name1,name2)
    
    if "uncle" in input:
        words = input.split()
        name1 = words[0]
        name1 = convertToLowerCase(name1)
        name2 = words[5]
        name2 = convertToLowerCase(name2).rstrip(name2[-1])

        if name1 == name2:
            return "ERROR"
        else:
            return "uncle({},{})".format(name1,name2)
    
    if "aunt" in input:
        words = input.split()
        name1 = words[0]
        name1 = convertToLowerCase(name1)
        name2 = words[5]
        name2 = convertToLowerCase(name2).rstrip(name2[-1])

        if name1 == name2:
            return "ERROR"
        else:
            return "aunt({},{})".format(name1,name2)
        
    if "parents" in input:
        results = [""]
        words = input.split()
        name1 = words[0]
        name1 = convertToLowerCase(name1)
        name2 = words[2]
        name2 = convertToLowerCase(name2)
        name3 = words[-1]
        name3 = convertToLowerCase(name3).rstrip(name3[-1])

        if(name1 == name2):
            return "ERROR"
        elif(name2 == name3):
            return "ERROR"
        elif(name1 == name3):
            return "ERROR"
        else:
            results.remove("")
            results.append("parent({},{})".format(name1,name3))
            results.append("parent({},{})".format(name2,name3))
            return results


# Converts a question to its PROLOG equivalent.
def convertToQueryInProlog(input):
    if "siblings" in input and "Who" in input:
        words = input.split()
        name = words[-1]
        name = convertToLowerCase(name)
        return "siblings({},{})".format(name.rstrip(name[-1]),"Who")
    
    elif "siblings" in input and "Are" in input:
        words = input.split()
        name1 = words[1]
        name1 = convertToLowerCase(name1)
        name2 = words[3]
        name2 = convertToLowerCase(name2) # Are X and Y siblings?
        return "sibling({},{});siblings({},{})".format(name1,name2,name1,name2)
    
    elif "female" in input:
        words = input.split()
        name = words[1]
        name = convertToLowerCase(name)
        return "female({})".format(name)
    
    elif "male" in input:
        words = input.split()
        name = words[1]
        name = convertToLowerCase(name)
        return "male({})".format(name)
    
    elif "sisters" in input:
        words = input.split()
        name = words[-1]
        name = convertToLowerCase(name)
        return "sister({},{})".format("Who",name.rstrip(name[-1]))
    
    elif "sister" in input:
        words = input.split()
        name1 = words[1]
        name1 = convertToLowerCase(name1)
        name2 = words[5]
        name2 = convertToLowerCase(name2)
        return "sister({},{})".format(name1,name2.rstrip(name2[-1]))
    
    elif "brothers" in input:
        words = input.split()
        name = words[-1]
        name = convertToLowerCase(name)
        return "brother({},{})".format("Who",name.rstrip(name[-1]))
    
    elif "brother" in input:
        words = input.split()
        name1 = words[1]
        name1 = convertToLowerCase(name1)
        name2 = words[5]
        name2 = convertToLowerCase(name2)
        return "brother({},{})".format(name1,name2.rstrip(name2[-1]))
    
    elif "grandmother" in input:
        words = input.split()
        name1 = words[1]
        name1 = convertToLowerCase(name1)
        name2 = words[5]
        name2 = convertToLowerCase(name2)
        return "grandmother({},{})".format(name1,name2.rstrip(name2[-1]))
    
    elif "grandfather" in input:
        words = input.split()
        name1 = words[1]
        name1 = convertToLowerCase(name1)
        name2 = words[5]
        name2 = convertToLowerCase(name2)
        return "grandfather({},{})".format(name1,name2.rstrip(name2[-1]))
    
    elif "mother" in input and "Is" in input:
        words = input.split()
        name1 = words[1]
        name1 = convertToLowerCase(name1)
        name2 = words[5]
        name2 = convertToLowerCase(name2)
        return "mother({},{})".format(name1,name2.rstrip(name2[-1]))
    
    elif "mother" in input and "Who" in input:
        words = input.split()
        name = words[-1]
        name = convertToLowerCase(name)
        return "mother(Who,{})".format(name.rstrip(name[-1]))

    elif "father" in input and "Is" in input:
        words = input.split()
        name1 = words[1]
        name1 = convertToLowerCase(name1)
        name2 = words[5]
        name2 = convertToLowerCase(name2)
        return "father({},{})".format(name1,name2.rstrip(name2[-1]))
    
    elif "father" in input and "Who" in input:
        words = input.split()
        name = words[-1]
        name = convertToLowerCase(name)
        return "father(Who,{})".format(name.rstrip(name[-1]))
    
    elif "daughters" in input:
        words = input.split()
        name = words[-1]
        name = convertToLowerCase(name)
        return "daughter({},{})".format("Who",name.rstrip(name[-1]))
    
    elif "daughter" in input:
        words = input.split()
        name1 = words[1]
        name1 = convertToLowerCase(name1)
        name2 = words[5]
        name2 = convertToLowerCase(name2)
        return "daughter({},{})".format(name1,name2.rstrip(name2[-1]))
    
    elif "sons" in input:
        words = input.split()
        name = words[-1]
        name = convertToLowerCase(name)
        return "son({},{})".format("Who",name.rstrip(name[-1]))
    
    elif "son" in input:
        words = input.split()
        name1 = words[1]
        name1 = convertToLowerCase(name1)
        name2 = words[5]
        name2 = convertToLowerCase(name2)
        return "son({},{})".format(name1,name2.rstrip(name2[-1]))
    
    elif "children" in input and "Are" in input:
        words = input.split()
        name1 = words[1]
        name1 = convertToLowerCase(name1)
        name1 = name1.rstrip(name1[-1])
        name2 = words[2]
        name2 = convertToLowerCase(name2)
        name3 = words[4]
        name3 = convertToLowerCase(name3)
        name4 = words[-1]
        name4 = convertToLowerCase(name4)
        name4 = name4.rstrip(name4[-1])
        return "child({},{}),child({},{}),child({},{})".format(name1,name4,name2,name4,name3,name4)

    elif "children" in input:
        words = input.split()
        name = words[-1]
        name = convertToLowerCase(name)
        return "child({},{})".format("Who",name.rstrip(name[-1]))
    
    elif "child" in input:
        words = input.split()
        name1 = words[1]
        name1 = convertToLowerCase(name1)
        name2 = words[5]
        name2 = convertToLowerCase(name2)
        return "child({},{})".format(name1,name2.rstrip(name2[-1]))
    
    elif "uncle" in input:
        words = input.split()
        name1 = words[1]
        name1 = convertToLowerCase(name1)
        name2 = words[5]
        name2 = convertToLowerCase(name2)
        return "uncle({},{})".format(name1,name2.rstrip(name2[-1]))    

    elif "aunt" in input:
        words = input.split()
        name1 = words[1]
        name1 = convertToLowerCase(name1)
        name2 = words[5]
        name2 = convertToLowerCase(name2)
        return "aunt({},{})".format(name1,name2.rstrip(name2[-1]))
    
    elif "relatives" in input:
        words = input.split()
        name1 = words[1]
        name1 = convertToLowerCase(name1)
        name2 = words[3]
        name2 = convertToLowerCase(name2)
        return "relatives({},{});relative({},{})".format(name1,name2)
    
    elif "Who" in input and "parents" in input:
        words = input.split()
        name = words[-1]
        name = convertToLowerCase(name)
        return "parent(Who,{})".format(name.rstrip(name[-1]))
    
    elif "Are" in input and "parents" in input:
        words = input.split()
        name1 = words[1]
        name1 = convertToLowerCase(name1)
        name2 = words[3]
        name2 = convertToLowerCase(name2)
        name3 = words[-1]
        name3 = convertToLowerCase(name3)
        name3 = name3.rstrip(name3[-1])
        return "parent({},{}),parent({},{})".format(name1,name3,name2,name3)
    




