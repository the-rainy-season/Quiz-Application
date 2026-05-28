#include <iostream>
#include <vector>
using namespace std;

// OOPS Concept: Class
class Question
{
private:
    string question;
    string option1, option2, option3, option4;
    int correctAnswer;

public:
    // Constructor
    Question(string q, string o1, string o2,
             string o3, string o4, int ans)
    {
        question = q;
        option1 = o1;
        option2 = o2;
        option3 = o3;
        option4 = o4;
        correctAnswer = ans;
    }

    // Display Question
    void displayQuestion()
    {
        cout << "\n" << question << endl;
        cout << "1. " << option1 << endl;
        cout << "2. " << option2 << endl;
        cout << "3. " << option3 << endl;
        cout << "4. " << option4 << endl;
    }

    // Check Answer
    bool checkAnswer(int userAnswer)
    {
        return userAnswer == correctAnswer;
    }

    // Display Correct Answer
    void showCorrectAnswer()
    {
        cout << "Correct Answer: ";

        switch(correctAnswer)
        {
            case 1:
                cout << option1;
                break;

            case 2:
                cout << option2;
                break;

            case 3:
                cout << option3;
                break;

            case 4:
                cout << option4;
                break;
        }

        cout << endl;
    }
};

int main()
{
    int score = 0;
    int answer;

    // Vector storing Question objects
    vector<Question> quiz = {

        Question(
            "What is the capital of India?",
            "Mumbai",
            "Delhi",
            "Kolkata",
            "Chennai",
            2),

        Question(
            "Which language is used for web development?",
            "HTML",
            "C++",
            "Python",
            "Java",
            1),

        Question(
            "Which data structure follows FIFO?",
            "Stack",
            "Queue",
            "Tree",
            "Graph",
            2),

        Question(
            "Who is known as the father of C++?",
            "Dennis Ritchie",
            "James Gosling",
            "Bjarne Stroustrup",
            "Guido van Rossum",
            3),

        Question(
            "Which symbol is used for comments in C++?",
            "//",
            "##",
            "**",
            "@@",
            1)
    };

    // To store user answers
    vector<int> userAnswers;

    cout << "=====================================\n";
    cout << "         QUIZ APPLICATION\n";
    cout << "=====================================\n";

    // Quiz Loop
    for (int i = 0; i < quiz.size(); i++)
    {
        quiz[i].displayQuestion();

        cout << "\nEnter your answer (1-4): ";
        cin >> answer;

        userAnswers.push_back(answer);

        if (quiz[i].checkAnswer(answer))
        {
            cout << "Correct Answer!\n";
            score++;
        }
        else
        {
            cout << "Wrong Answer!\n";
        }
    }

    // Final Result
    cout << "\n=====================================\n";
    cout << "          QUIZ RESULT\n";
    cout << "=====================================\n";

    cout << "Your Score: " << score
         << " / " << quiz.size() << endl;

    // Performance Message
    if (score == quiz.size())
        cout << "Excellent Performance!\n";

    else if (score >= 3)
        cout << "Good Job!\n";

    else
        cout << "Keep Practicing!\n";

    // Display Correct Answers
    cout << "\n=====================================\n";
    cout << "        CORRECT ANSWERS\n";
    cout << "=====================================\n";

    for (int i = 0; i < quiz.size(); i++)
    {
        cout << "\nQuestion " << i + 1 << ": ";
        quiz[i].showCorrectAnswer();
    }

    cout << "\n=====================================\n";

    return 0;
}