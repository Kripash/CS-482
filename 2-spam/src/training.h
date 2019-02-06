//author: Kripash Shrestha
//file: training.h

//this file is the header file for the training executable and portion of the bayesian naive spam filter. 



#include <stdio.h> 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <ctype.h>
#include <map>
#include <math.h> 
#include <stdint.h>
#include <iomanip>

using namespace std;



//struct used to store the words in the text messages
struct TextWords
{
	string word = "\0";
	int num_appearances = 0;
	int num_appearances_in_spam = 0;
	int num_appearances_in_ham = 0;
	double probability_of_ham = 0.0;
	double probability_of_spam = 0.0;

};

//used to store each text message in the training file
class TextMessage
{
	public:

	string message;
	string removed_special_characters;
	vector <string> words_in_message;
	bool spam;
	int number_of_words;

	TextMessage();
	~TextMessage();
	void setSpam(bool spam_or_ham);
	void setNumberOfWords(int words);
	void setWordsInMessage(string message_to_store);
	void printTextMessageInfo();
	void clear();
};


/**
 * This is the Constructor for the textmessage class, sets the proper values to be default values.
 *
 * @param none
 * @return none
 *
 * @pre none.
 * @post sets up the default object with the default values set for the types for each object.
 *
 */
TextMessage::TextMessage()
{
	message.clear();
	removed_special_characters.clear();
	number_of_words = 0;
	spam = false;
	words_in_message.clear();
}

/**
 * This is the destructor class, nothing is needed to be done as there is no use of dynamic memory.
 *
 * @param none
 * @return none
 *
 * @pre none.
 * @post destroys the textmessage object.
 *
 */
TextMessage::~TextMessage()
{

}

/**
 * This is clear function for the text message class, its set all the values of the types to be the default, essentially the constructor.
 *
 * @param none
 * @return none
 *
 * @pre none.
 * @post sets up the default object with the default values set for the types for each object.
 *
 */
void TextMessage::clear()
{
	message.clear();
	removed_special_characters.clear();
	number_of_words = 0;
	spam = false;
	words_in_message.clear();
}

/**
 * This is the setSpam function of the TextMessage class and it sets the message to be recognized as spam or ham.
 *
 * @param bool spam_or_ham, which tells the message if it is ham or spam.
 * @return none
 *
 * @pre none.
 * @post sets the object to be recognized as spam or ham.
 *
 */
void TextMessage::setSpam(bool spam_or_ham)
{
	spam = spam_or_ham;
}

/**
 * This is the setNumberOfWords function of the TextMessage class and it sets the nubmer of words in the message.
 *
 * @param int words, the number of words in the message.
 * @return none
 *
 * @pre none.
 * @post sets the object to contain the number of words in the messae.
 *
 */
void TextMessage::setNumberOfWords(int words)
{
	number_of_words = words;
}

/**
 * This is the seWordsInMessage function of the TextMessage class and it sets the message of the object.
 *
 * @param string message_to_store, the message to store in the object, which is the text string.
 * @return none
 *
 * @pre none.
 * @post sets the object to contain the message in the text.
 *
 */
void TextMessage::setWordsInMessage(string message_to_store)
{
	message = message_to_store;

}

/**
 * This is the printTextMessageInfo function of the TextMessage class.
 * It prints out the values of the types in the object and is used for debugging purposes.
 *
 * @param none
 * @return none
 *
 * @pre none.
 * @post none
 *
 */
void TextMessage::printTextMessageInfo()
{
	cout << "Message : " << message << endl;
	cout << "Parsed string is: " << removed_special_characters << endl;
	cout << "Spam: " << boolalpha << spam << endl;
	cout << "Number of Words: " << number_of_words << endl;
	if(number_of_words != words_in_message.size())
	{
		cout << "Issue with Parsing!" << " Number of Words: " << number_of_words << " Words Stored: " << words_in_message.size() << endl;
		cout << "The message is: " << message << endl;
		cout << "Parsed string is: " << removed_special_characters << endl;
		for(int i = 0; i < words_in_message.size(); i++)
		{
			cout <<  (i + 1) << " : " << words_in_message[i] << endl;
		}
	}
	for(int i = 0; i < words_in_message.size(); i++)
	{
		cout <<  (i + 1) << " : " << words_in_message[i] << endl;
	}

}

/**
 * This is the removeSpecialCharacters function.
 * The function removes all special characters from a given string and returns it.
 * Anything that is not a space, number of space is removed.
 *
 * @param string message, the string to parse and remove special characters.
 * @return returns the parsed string with no special characters.
 *
 * @pre none.
 * @post the string no longer contains special chracters.
 *
 */
string removeSpecialCharacters(string message)
{
	int i = 0;
	int len = message.length();
	while(i < len)
	{
		char c = message[i];
		if(((c>='0')&&(c<='9'))||((c>='A')&&(c<='Z'))||((c>='a')&&(c<='z')) || c == ' ') 
		{
			++i;
		}
		else
		{
			message.erase(i,1);
			--len;
		}
	}
	return message;
}

/**
 * This is the countWordsInString function.
 * The function counts the number of words in a given string/text message.
 * the function pushes the words into a text message object's words_in_message vector.
 *
 * @param string message, the string to count the number of words and dissect.
 * @param TextMessage &parsed, the object the string belongs to, which will be dissected.
 * @return Returns the number of words in the string.
 *
 * @pre none.
 * @post the function will parse the words in the message and push it into the text message object's vector.
 *
 */
int countWordsInString(string message, TextMessage &parsed)
{
	int words = 0;
	int len = message.length();
	int i = 0;
	string word;
	parsed.removed_special_characters = message;
	if(!(message.find_first_not_of(' ') != std::string::npos))
	{
		//cout << "The message is: " << parsed.message << endl;
		return 0;
	}

	while(isspace(message.at(i)))
	{
		i++;
	}

	for(i; i < len; i++)
	{
		if(isspace(message.at(i)))
		{
			words++;
			//cout << word << endl;
			//cout << i << " " << message.length() << endl;
			parsed.words_in_message.push_back(word);
			word.clear();
			while(((i + 1) < len) && isspace(message.at(i + 1)))
			{
				i++;
				//cout << "Another White space" << endl;
				//cout << i << " " << message.length() << endl;
				if(message.at(i) == '\0')
				{
					//cout << word << endl;
					words--;
				}
			}
		}
		else
		{
			word = word + message.at(i);
		}
	}
	if(word.length() > 0 && word != " ")
	{
		//cout << word << endl;
		parsed.words_in_message.push_back(word);
	}
	//cout << words + 1 << endl;
	parsed.setNumberOfWords(parsed.words_in_message.size());
	return words + 1;
}

/**
 * This is the readTrainingFile function.
 * The function reads the training file and pushes the messages into the given vector, line by line.
 *
 * @param string training file, the training file to read the data from. 
 * @param vector<string> &spam_training_vector, the vector to contain the training data line by line.
 * @return none
 *
 * @pre none.
 * @post The training data is read and stored.
 *
 */
void readTrainingFile(vector<string> &spam_training_vector, string training_file)
{
	string push_back;
	ifstream myfile;
	myfile.open(training_file);
	if(!myfile.is_open())
	{
		cout << "Error Readinng " << training_file << endl;
		exit(0);
	}
	while(!myfile.eof())
	{  
		getline(myfile, push_back);
		spam_training_vector.push_back(push_back);
	}
	myfile.close();
}

/**
 * This is the praseStrings function.
 * The function goes through the spam_training_vector training data and prases the data.
 * the data is parsed by object, and objects in the words and stored based on if the object is spam or ham.
 *
 * @param vector<string> &spam_training_vector, the vector that contains the training data line by line.
 * @param vector<TextMessages> &text_messages, the vector to contains the textmessages objects based on the training data.
 * @return none
 *
 * @pre none.
 * @post The training data is parsed and stored into a TextMessage vector.
 *
 */
void parseStrings(vector<string> &spam_training_vector, vector<TextMessage> &text_messages)
{

	string temp;
	int position;
	string spam_or_ham;
	string text_message;
	TextMessage parsed;
		
	for(int i = 1; i < spam_training_vector.size(); i++)
	{
		//cout << i << endl;
		string temp = spam_training_vector[i];
		parsed.setWordsInMessage(temp);
		position = temp.find(",");
		spam_or_ham = temp.substr(0, position);
		if(spam_or_ham == "spam")
		{
			parsed.setSpam(true);
		}
		else if(spam_or_ham == "ham")
		{
			parsed.setSpam(false);
		}
		parsed.setNumberOfWords(0);
		text_message = temp.substr(position + 1);
		//cout << "---" << spam_or_ham << "---" << endl;
		//cout << "---" << text_message << "---" << endl;
		string erased = removeSpecialCharacters(text_message);
		//cout << "Erased Message: " <<  erased << "---" << endl;
		int num_words = countWordsInString(erased, parsed);
		//parsed.setNumberOfWords(num_words);
		//parsed.printTextMessageInfo();
		if(num_words > 0)
		{
			text_messages.push_back(parsed);
		}
		parsed.clear();
	}
	//cout << spam_training_vector.size() << endl;
}

/**
 * This is the bayesianfilter function.
 * The function goes through text_messages vector and stores the data of each word based on the textmessage.
 * The function is mention to get the data word by word, ssuch as number of appearances, num_appearances in spam, in ham, etc..
 *
 * @param vector<string> &spam_training_vector, the vector that contains the training data line by line.
 * @param vector<TextMessages> &text_messages, the vector that contains the textmessages objects based on the training data.
 * @param map<string, Textwords> &bayesian_map, contains the map for all of the individual words in the text_messages.
 * @param uint32_t &num_of_spam_words, total number of spam words
 * @param uint32_t &num_of_ham_words, total number of ham words
 * @return none
 *
 * @pre none.
 * @post The training data is appropriately calculated for the bayesian math.
 *
 */
void bayesianFilter(vector<TextMessage> text_messages, vector<TextWords> &text_words, map<string, TextWords> &bayesian_map, uint32_t &num_of_spam_words, uint32_t &num_of_ham_words)
{
	for(int i = 0; i < text_messages.size(); i++)
	{
		for(int j = 0; j < text_messages[i].words_in_message.size(); j++)
		{
			//cout << "Message : " << i << " Word: " << j << " -> " << text_messages[i].words_in_message[j] << endl;
			if(bayesian_map.count(text_messages[i].words_in_message[j]) == 0)
			{
				TextWords temp;
				temp.word =  text_messages[i].words_in_message[j];
				temp.num_appearances++;
				if(text_messages[i].spam)
				{
					num_of_spam_words++;
					temp.num_appearances_in_spam++;	
				}
				else if(!text_messages[i].spam)
				{
					num_of_ham_words++;
					temp.num_appearances_in_ham++;
				}
				text_words.push_back(temp);
				bayesian_map.insert(pair<string, TextWords>(temp.word, temp));
			}
			else if(bayesian_map.count(text_messages[i].words_in_message[j]) == 1)
			{
				TextWords temp = bayesian_map.find(text_messages[i].words_in_message[j]) -> second;
				temp.num_appearances++;
				if(text_messages[i].spam)
				{
					num_of_spam_words++;
					temp.num_appearances_in_spam++;	
				}
				else if(!text_messages[i].spam)
				{
					num_of_ham_words++;
					temp.num_appearances_in_ham++;
				}
				map<string, TextWords>::iterator find_iterator;
				find_iterator = bayesian_map.find(temp.word);
				if(find_iterator != bayesian_map.end())
				{
					find_iterator -> second = temp;
					//TextWords test = find_iterator -> second;
					//cout << "Word: " << test.word << endl;
					//cout << "Appearances: " << test.num_appearances << endl;
					//cout << "Spam Appearances: " << test.num_appearances_in_spam << endl;
					//cout << "Ham Appearances: " << test.num_appearances_in_ham << endl;
					//cout << "Spam Probability: " << test.probability_of_spam << endl;
					//cout << "Ham Probability: " << test.probability_of_ham << endl;
				}
			} 
			else if((bayesian_map.count(text_messages[i].words_in_message[j]) > 1 ))
			{
				cout << "ERROR: Word is Already Mapped!" << endl;
			}
		}
	}
}

/**
 * This is the claculateProbabilities function.
 * The function goes through text_messages vector and map and calcuilates the probaiblities for each vector. 
 * I realized that this is used in the classify file but I still have it for this one as well.
 *
 * @param vector<TextMessages> &text_messages, the vector that contains the textmessages objects based on the training data.
 * @param map<string, Textwords> &bayesian_map, contains the map for all of the individual words in the text_messages.
 * @param uint32_t &num_of_spam_words, total number of spam words
 * @param uint32_t &num_of_ham_words, total number of ham words
 * @return none
 *
 * @pre none.
 * @post The training data probabilities are properly calculated.
 *
 */
void calculateProbabilities(vector<TextWords> &text_words, uint32_t num_of_spam_words, uint32_t num_of_ham_words, map<string, TextWords> &bayesian_map)
{

	for(int i = 0; i < text_words.size(); i++)
	{
		map<string, TextWords>::iterator find_iterator;
		find_iterator = bayesian_map.find(text_words[i].word);
		text_words[i] = find_iterator -> second;
	}

	for(int i = 0; i < text_words.size(); i++)
	{
		text_words[i].probability_of_spam = ((double)text_words[i].num_appearances_in_spam/(double)num_of_spam_words);
		text_words[i].probability_of_ham = ((double)text_words[i].num_appearances_in_ham/(double)num_of_ham_words);
		map<string, TextWords>::iterator find_iterator;
		find_iterator = bayesian_map.find(text_words[i].word);
		if(find_iterator != bayesian_map.end())
		{
			find_iterator -> second = text_words[i];
		}
	}
}
 /**
 * This is the outputToFiles function.
 * The function goes outputs to the given command line argument files for the Spam and Ham probability files.
 * The function outputs it as count of total number of words, 
 * word " " number of word occurences 
 *
 * @param string spam_probability_file, the file for the spam probability file so the data can be written there.
 * @param string ham_probability_file, the file for the ham probability file so the data can be written there.
 * @param vector<TextWords> &text_words, the vector that contains the words data to be printed out.
 * @param map<string, Textwords> &bayesian_map, contains the map for all of the individual words in the text_messages.
 * @param uint32_t &num_of_spam_words, total number of spam words
 * @param uint32_t &num_of_ham_words, total number of ham words
 * @return none
 *
 * @pre none.
 * @post Outputs the data for the spam and ham probability files to the spam and ham probability files.
 *
 */
void outputToFiles(string spam_probability_file, string ham_probability_file, vector<TextWords> &text_words, uint32_t num_of_spam_words, uint32_t num_of_ham_words)
{
	ofstream myfile;
	myfile.open(spam_probability_file);
	if(!myfile.is_open())
	{
		cout << "Error Opening " << spam_probability_file << endl;
		exit(0);
	}
	myfile << num_of_spam_words << endl;
	for(int i = 0; i < text_words.size(); i++)
	{
		//cout << text_words[i].num_appearances_in_spam << " " << text_words[i].num_appearances_in_ham << endl;
		if(i == text_words.size() - 1)
		{
			myfile << text_words[i].word << " " << text_words[i].num_appearances_in_spam;
		}
		else
		{
			myfile << text_words[i].word << " " << text_words[i].num_appearances_in_spam << endl;
		}
	}
	myfile.close();

	ofstream hamfile;
	hamfile.open(ham_probability_file);
	if(!hamfile.is_open())
	{
		cout << "Error Opening " << ham_probability_file << endl;
		exit(0);
	}
	hamfile << num_of_ham_words << endl;
	for(int i = 0; i < text_words.size(); i++)
	{
		if(i == text_words.size() - 1)
		{
			hamfile << text_words[i].word << " " << text_words[i].num_appearances_in_ham;
		}
		else
		{
			hamfile << text_words[i].word << " " << text_words[i].num_appearances_in_ham << endl;
		}

	}
	hamfile.close();
}


