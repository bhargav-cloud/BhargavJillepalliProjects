import random
from words import words
import string

def get_valid(words):
    word = random.choice(words)
    while '-' in word or ' ' in word:
        word = random.choice(words)
    return word
def hangman():
    word = get_valid(words)
    word_letter = set(word)
    alphabet = set(string.ascii_uppercase)
    used_letters = set()

    lives = 6
    #gets user input
    while len(word_letter) > 0 and lives > 0 :
        print('You used these letters ',' '.join(used_letters))
        word_list = [letter if letter in used_letters else '-' for letter in word]
        print('Current word: ',' '.join(word_list))
    user_letter = input("Guess a letter: ").upper()
    if user_letter in alphabet - used_letters:
        used_letters.add(user_letter)
        if user_letter in word_letter:
            word_letter.remove(user_letter)
        else:
            lives = lives - 1
            print('Letter not in word')
    elif user_letter in used_letter:
        print("You used this character already. Try Again!!!!")
    else:
        print("Invalid Choice.please Try Again")
if lives > 0:
    print('You were killed, sorry. The word was ', word)
else:

    print('You guessed the word ', word, '!!')

user_input = input('Type Something: ')
print(user_input)
