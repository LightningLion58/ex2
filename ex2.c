/******************
Name: Tom Yaeger
ID: 216082867
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
    //Menu:

    //`option` - Will store the option that the user selected from the menu.
    int option;
    do {
        //Print the menu:
        printf("Choose an option:\n");
        printf("\t1. Happy Face\n");
        printf("\t2. Balanced Number\n");
        printf("\t3. Generous Number\n");
        printf("\t4. Circle Of Joy\n");
        printf("\t5. Happy Numbers\n");
        printf("\t6. Festival Of Laughter\n");
        printf("\t7. Exit\n");
        scanf("%d", &option); //Get input from the user. (an integer representing the option the user chose)

        //Go through all the possible options for `option:`
        switch (option) {
            /* 1. Happy Face
             * Case 1: Draw Happy Face with given symbols for eyes, nose and mouth
            */
            case 1:
                char eyesChar, noseChar, mouthChar;
                int faceSize;
                //Ask the user to enter 3 characters (non-empty/space characters)
                printf("Enter symbols for the eyes, nose, and mouth:\n");
                scanf(" %c %c %c", &eyesChar, &noseChar, &mouthChar);
                printf("Enter face size:");
                //Scan for input (face size) until the input is valid: (Print an error message if not)
                while (1) {
                    scanf("%d", &faceSize);
                    if (faceSize % 2 == 1 && faceSize > 0) { //If the input is valid, break the loop
                        break;
                    }
                    printf("The face's size must be an odd and positive number, please try again:\n");
                }

                /* Print the face
                 * I chose to print the face in the following way:
                 * 1. Print`eyeChar`, followed by `faceSize` spaces (using * to specify the width), followed by another `eyeChar`
                 *    and then go down a line (\n)
                 * 2. Print (1 + faceSize/2) spaces using * to specify the width of %c.
                 *    and then go down a line again(\n)
                 *    This is the formula I came up with (1 + faceSize/2), given the examples from the document.
                 * 3. Print \ and then print `faceSize` times the `mouthChar` (using a for loop), and then print a '/'.
                 *    (and then another \n)
                 */

                //(Step 1:): Print `eyesChar`, and then `faceSize` times spaces (using width), and then print another `eyesChar`:
                printf("%c%*c%c\n", eyesChar, faceSize, ' ', eyesChar);
                //(Step 2:): Print (1 + faceSize/2) times spaces, followed by `noseChar` and a new line (\n).
                printf("%*c%c\n", 1 + faceSize/2, ' ', noseChar);

                printf("\\");
                for (int i = 0; i < faceSize; i++) {
                    printf("%c", mouthChar);
                }
                printf("/\n");
                break;
            /* 2. Balanced Number:
             * Case 2: determine whether the sum of all digits to the left of the middle digit(s)
             * and the sum of all digits to the right of the middle digit(s) are equal
             */
            case 2:
                int num;
                printf("Enter a number: \n");
                //Scan for input until it is valid: (Print an error message if not)
                while (1) {
                    scanf("%d", &num);
                    if (num > 0) { //If the input is valid, break the loop
                        break;
                    }
                    printf("Only positive number is allowed, please try again:\n");
                }
                //Count the digits in `num`:
                int copy = num, digits = 0;
                while (copy != 0) {
                    copy /= 10;
                    digits++;
                }
                int sumLeft = 0, sumRight = 0;
                for(int i = 1; i <= digits; i++) {
                    if(digits % 2 == 1 && i == (digits/2)+1) {
                        num /= 10; //Skip the number that is in the middle (get rid of it).
                        i++;
                    }
                    if(i <= digits/2) {
                        sumRight += num % 10;
                    } else {
                        sumLeft += num % 10;
                    }
                    num /= 10;
                }
                if(sumLeft == sumRight) {
                   printf("This number is balanced and brings harmony!\n");
                } else {
                    printf("This number isn't balanced and destroys harmony.\n");
                }
                break;
            /* 7. Exit
             * Case 7: End the program.
             */
            case 7: //If the user picked 7 (Exit), that is the only option left:
                printf("Thank you for your journey through Numeria!");
                break;
            //If the switch enters the default case, it means the input given from the user is not valid.
            default:
                printf("This option is not available, please try again.\n");
        }
    } while (option != 7); //Repeat everything unless the user chose 7.

    // Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
    /* Examples:
    Abudant: 12, 20, 24
    Not Abudant: 3, 7, 10
    Please notice: the number has to be bigger than 0.
    */

    // Case 4: determine wether a number is a prime.
    /* Examples:
    This one brings joy: 3, 5, 11
    This one does not bring joy: 15, 8, 99
    Please notice: the number has to be bigger than 0.
    */


    // Happy numbers: Print all the happy numbers between 1 to the given number.
    // Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
    /* Examples:
    Happy :) : 7, 10
    Not Happy :( : 5, 9
    Please notice: the number has to be bigger than 0.
    */

    // Festival of Laughter: Prints all the numbers between 1 the given number:
    // and replace with "Smile!" every number that divided by the given smile number
    // and replace with "Cheer!" every number that divided by the given cheer number
    // and replace with "Festival!" every number that divided by both of them
    /* Example:
    6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
    */
    return 0;
}
