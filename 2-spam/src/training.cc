//author: Kripash Shrestha
//file: training.cc 

//this file is the main file for the training executable and portion of the bayesian naive spam filter. 


#include "training.h"

int main(int argc, char **argv)
{
	string training_file;
	string spam_probability_file;
	string ham_probability_file;

	//check if the arguments match up and if they do, properly get them.
	if(argc != 7)
	{
		cout << "Invalid Amount of Command line Arguments!" << endl;
		exit(0);
	}
	else
	{
		training_file = argv[2];
		spam_probability_file = argv[4];
		ham_probability_file = argv[6];
	}
	vector<string> spam_training_vector;
	vector<TextMessage> text_messages;
	vector<TextWords>   text_words;
	map<string, TextWords> bayesian_map;
	uint32_t num_of_spam_words = 0;
	uint32_t num_of_ham_words = 0;

	//read the training file
	readTrainingFile(spam_training_vector, training_file);
	//parse the strings from the training file
	parseStrings(spam_training_vector, text_messages);
	//do some checks and apply the bayesian filter
	bayesianFilter(text_messages, text_words, bayesian_map, num_of_spam_words, num_of_ham_words);
	//cout << "Total Words: " << num_of_ham_words + num_of_spam_words << endl;
	//calculate the probablities for the words, although not used for this portion
	calculateProbabilities(text_words, num_of_spam_words, num_of_ham_words, bayesian_map);
	/*for(int i = 0; i < text_words.size(); i++)
	{
		if(text_words[i].num_appearances == 0 )
		{
			cout << "Word: " << text_words[i].word << endl;
			cout << "Appearances: " << text_words[i].num_appearances << endl;
			cout << "Spam Appearances: " << text_words[i].num_appearances_in_spam << endl;
			cout << "Ham Appearances: " << text_words[i].num_appearances_in_ham << endl;
			cout << "Spam Probability: " << setprecision(20) << text_words[i].probability_of_spam << endl;
			cout << "Ham Probability: " << setprecision(20) << text_words[i].probability_of_ham << endl;
		}
	}
	cout << "Number of Spam Words: " << num_of_spam_words << endl;
	cout << "Number of Ham Words: " << num_of_ham_words << endl;*/
	//output the data to the files.
	outputToFiles(spam_probability_file, ham_probability_file, text_words, num_of_spam_words, num_of_ham_words);

	int num_spam = 0;
	int num_ham = 0;
	/*for(int i = 0; i < text_messages.size(); i ++)
	{
		if(text_messages[i].spam)
		{
			num_spam++;
		}
		else if(!text_messages[i].spam)
		{
			num_ham++;
		}
	}
	cout << "Spam: " << num_spam << endl;
	cout << "Ham: " << num_ham << endl;
	*/
	return 0;
}

//g++ -std=c++11 -o training training.cpp
//./training -i spam.csv -os spam.txt -oh ham.txt

