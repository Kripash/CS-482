//author: Kripash Shrestha
//file: classify.cc 

//this file is the main file for the classify executable and portion of the bayesian naive spam filter. 

#include "classify.h"

int main(int argc, char **argv)
{
	string training_file;
	string spam_probability_file;
	string ham_probability_file;
	string classify_file;

	//check if the arguments match up and if they do, properly get them.
	if(argc != 9)
	{
		cout << "Invalid Amount of Command line Arguments!" << endl;
		exit(0);
	}
	else
	{
		training_file = argv[2];
		spam_probability_file = argv[4];
		ham_probability_file = argv[6];
		classify_file = argv[8];
	}
	vector<string> classify_vector;
	vector<TextMessage> text_messages;
	vector<TextWords>   text_words;
	map<string, TextWords> bayesian_map;

	uint32_t num_of_spam_words = 0;
	uint32_t num_of_ham_words = 0;

	//read the training/classify file
	readTrainingFile(classify_vector, training_file);
	//parse the strings from the file
	parseStrings(classify_vector, text_messages); 
	//read the spam probaility file
	readProbabilityFiles(true, spam_probability_file, num_of_spam_words, bayesian_map, text_words);
	//read the ham probability file
	readProbabilityFiles(false, ham_probability_file, num_of_ham_words, bayesian_map, text_words);
	//calculate probabilities
	calculateProbabilities(text_words, num_of_spam_words, num_of_ham_words, bayesian_map);
	//figure out if the message is spam or ham
	spamOrHam(text_messages, text_words, bayesian_map, (num_of_spam_words + num_of_ham_words), num_of_spam_words, num_of_ham_words);


	//print out if the text message is spam or ham corresponding to the order it was read in
	ofstream classifyoutput;
	classifyoutput.open(classify_file);
	if(!classifyoutput.is_open())
	{
		cout << "Error Opening " << classify_file << endl;
		exit(0);
	}

	int num_spam = 0;
	int num_ham = 0;
	for(int i = 0; i < text_messages.size(); i++)
	{
		//cout << "Message: " << text_messages[i].message << endl;
		//cout << "Probability of Spam: " << text_messages[i].prob_of_spam << endl;
		//cout << "Probability of Ham: " << text_messages[i].prob_of_ham << endl;
		//cout << "Log Ratio: " << text_messages[i].log_ratio << endl << endl;
		if(text_messages[i].log_ratio < 1.0)
		{
			classifyoutput << "spam" << endl;
			num_spam++;
		}
		else if(text_messages[i].log_ratio >= 1.0)
		{
			classifyoutput << "ham" << endl;
			num_ham++;
		}
	}

	classifyoutput.close();
			
	//cout << classify_vector.size() << endl;
	//cout << text_messages.size() << endl;
	//cout << "Spam: " << num_spam << endl;
	//cout << "Ham: " << num_ham << endl;	

	return 0;
}

