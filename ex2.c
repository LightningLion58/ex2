/******************
Name: Tom Yaeger
ID: 216082867
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
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

        //`num` - Since multiple cases require the user to enter a number, I defined the variable outside the scope.
        int num;

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
                printf("Enter face size:\n");
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
                //Go through all the digits in num:
                int sumLeft = 0, sumRight = 0;
                for(int i = 1; i <= digits; i++) {
                    if(digits % 2 == 1 && i == (digits/2)+1) {
                        num /= 10; //Skip the number that is in the middle (get rid of it).
                        i++;
                    }
                    if(i <= digits/2) { //If the digits are to the right of the number:
                        sumRight += num % 10; //Add them to the right sum.
                    } else { //If the digits are to the left of the number:
                        sumLeft += num % 10;  //Add them to the left sum.
                    }
                    num /= 10;
                }
                if(sumLeft == sumRight) {
                   printf("This number is balanced and brings harmony!\n");
                } else {
                    printf("This number isn't balanced and destroys harmony.\n");
                }
                break;
            /* 3. Generous Number:
             *  Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
             */
            case 3:
                //Scan for input until it is valid: (Print an error message if not)
                printf("Enter a number:\n");
                while (1) {
                    scanf("%d", &num);
                    if (num > 0) { //If the input is valid, break the loop
                        break;
                    }
                    printf("Only positive number is allowed, please try again:\n");
                }
                //Go through all the possible dividers (from 2 to num/2) and sum them up if they are proper dividers.
                int sumOfDividers = 0;
                for(int i = 2; i <= num/2; i++) {
                    if(num % i == 0) { //If `i` is a proper divider:
                        sumOfDividers += i; //Add `i` to the sum.
                    }
                }
                /*A number is generous if the sum of all its
                 proper dividers is bigger than itself: */
                if(sumOfDividers > num) {
                    printf("This number is generous!\n");
                } else {
                    printf("This number does not share.\n");
                }
                break;
            /* 4. Circle Of Joy
             * Case 4: determine whether a number is a prime.
             */
            case 4:
                //Scan for input until it is valid: (Print an error message if not)
                printf("Enter a number:\n");
                while (1) {
                    scanf("%d", &num);
                    if (num > 0) { //If the input is valid, break the loop
                        break;
                    }
                    printf("Only positive number is allowed, please try again:\n");
                }
                //Count the digits in `num`:
                int numCopy = num, digitCount = 0;
                while (numCopy != 0) {
                    numCopy /= 10;
                    digitCount++;
                }
                /*Reverse num by multiplying each digit by (digitCount-i) powers of 10.
                (e.g. for number 1234, we get: 4 * 1000 + 3 * 100 + 2 * 10 + 1)*/
                numCopy = num; //We need a copy so that we don't lose the original number.
                int reversedNum = 0;
                //For every digit:
                for(int i = 1; i <= digitCount; i++) {
                    //Calculate 10 to the power of digitCount-i:
                    int tenPower = 1;
                    for (int power = 0; power < digitCount-i; power++) {
                        tenPower *= 10;
                    }
                    /*For every digit:
                     * Multiply the rightest digit by 10 to the according power,
                     * and add it to reversedNum:
                     */
                    reversedNum += (numCopy%10) * tenPower;
                    numCopy/=10; //Get rid of the rightest digit.
                }
                //First assume they are both primes,
                int areBothPrimes = 1;
                if(num == 1) {
                    /*If the original number is one then we know they are not primes
                      (This is an edge case) */
                    areBothPrimes = 0;
                } else {
                    //Loop through all the possible dividers and find out if `num` or `reversedNum` aren't primes.
                    for(int i = 2; i <= reversedNum/2; i++) {
                        if(reversedNum % i == 0) {
                            areBothPrimes = 0;
                            break;
                        }
                    }
                    for(int i = 2; i <= num/2; i++) {
                        if(num % i == 0) {
                            areBothPrimes = 0;
                            break;
                        }
                    }
                }
                //Final prints:
                if(areBothPrimes) {
                    printf("This number completes the circle of joy!\n");
                } else {
                    printf("The circle remains incomplete.\n");
                }
                break;
            /* 5. Happy Numbers
             * Happy numbers: Print all the happy numbers between 1 to the given number.
             * Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
             */
            case 5:
                //Scan for input until it is valid: (Print an error message if not)
                printf("Enter a number:\n");
                while (1) {
                    scanf("%d", &num);
                    if (num > 0) { //If the input is valid, break the loop
                        break;
                    }
                    printf("Only positive number is allowed, please try again:\n");
                }
                //1 is a happy number (by definition):
                printf("Between 1 and %d only these numbers bring happiness: 1", num);
                for(int i = 7; i <= num; i++) { //From 7 to num (since 2 to 6 aren't happy numbers:)
                    int temp = i; //Create a temporary variable so that we don't lose the original value of `i`.
                    int sum = 0; //This will store the sum of digits squared.

                    /* While the sum isn't equal to 1 or 4:
                     * (If it is equal to 1, it is a happy number,
                     * otherwise if it's 4, it will enter an endless cycle,
                     * meaning it isn't a happy number)
                     */
                    while(sum != 1 && sum != 4) {
                        sum = 0;
                        do {
                            //Sum the digits squared:
                            int digit = temp % 10;
                            sum += digit*digit;
                            temp /= 10;
                        }while(temp); //While temp isn't 0.
                        //Our new number to sum the digits squared is the sum of the previous number:
                        temp = sum;
                    }
                    if(sum == 1) {
                        printf(" %d", i);
                    }
                }
                printf("\n");
                break;
            //6. Festival of Laughter
            // Festival of Laughter: Prints all the numbers between 1 the given number:
            // and replace with "Smile!" every number that divided by the given smile number
            // and replace with "Cheer!" every number that divided by the given cheer number
            // and replace with "Festival!" every number that divided by both of them
            case 6:
                int smileNumber  = 0, cheerNumber  = 0;
                printf("Enter a smile and cheer number:\n");
                do {
                    scanf(" smile:%d, cheer:%d", &smileNumber, &cheerNumber);
                    scanf("%*[^\n]"); //Clear the buffer.
                    if(smileNumber != cheerNumber && smileNumber > 0 && cheerNumber > 0) {
                        break;
                    }
                    printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
                } while(1);


                int maxNum;
                printf("Enter maximum number for the festival: \n");
                while (1) {
                    scanf("%d", &maxNum);
                    if (maxNum > 0) { //If the input is valid, break the loop
                        break;
                    }
                    printf("Only positive maximum number is allowed, please try again:\n");
                }
                //Iterate through all the numbers from 1 to `maxNum`:
                for(int i = 1; i <= maxNum; i++) {
                    //If they both divide the number, print Festival! (per requested in the exercise):
                    if((i % smileNumber == 0) && (i % cheerNumber == 0)) {
                        printf("Festival!\n");
                    } else if(i % smileNumber == 0) {
                        //If only `smileNumber` divides the number, print Smile! (per requested in the exercise):
                        printf("Smile!\n");
                    } else if(i % cheerNumber == 0) {
                        //If only `cheerNumber` divides the number, print Cheer! (per requested in the exercise):
                        printf("Cheer!\n");
                    } else {
                        printf("%d\n", i);
                    }
                }
                break;
            /* 7. Exit
             * Case 7: End the program.
             */
            case 7: //If the user picked 7 (Exit), that is the only option left:
                printf("Thank you for your journey through Numeria!\n");
                break;
            //If the switch enters the default case, it means the input given from the user is not valid.
            default:
                printf("This option is not available, please try again.\n");
        }
    } while (option != 7); //Repeat everything unless the user chose 7.
    return 0;
}