//author: Kripash Shrestha
//file: classify.h 

//this file is the header file for the classify executable and portion of the bayesian naive spam filter. 


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
	double prob_of_spam;
	double prob_of_ham;
	double log_ratio;

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
	prob_of_spam = 0;
	prob_of_ham = 0;
	log_ratio = 0;
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

void TextMessage::clear()
{
	message.clear();
	removed_special_characters.clear();
	number_of_words = 0;
	spam = false;
	words_in_message.clear();
	prob_of_spam = 0;
	prob_of_ham = 0;
	log_ratio = 0;
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
void TextMessage::setSpam(bool spam_or_ham)
{
	spam = spam_or_ham;
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
void TextMessage::setNumberOfWords(int words)
{
	number_of_words = words;
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
 * The function reads the training/classify file and pushes the messages into the given vector, line by line.
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
	string spam_or_ham;
	string text_message;
	TextMessage parsed;
		
	for(int i = 0; i < spam_training_vector.size(); i++)
	{
		//cout << i << endl;
		string temp = spam_training_vector[i];
		parsed.setWordsInMessage(temp);
		parsed.setNumberOfWords(0);
		//cout << "---" << spam_or_ham << "---" << endl;
		//cout << "---" << text_message << "---" << endl;
		text_message = temp;
		string erased = removeSpecialCharacters(text_message);
		int num_words = countWordsInString(erased, parsed);
		//parsed.setNumberOfWords(num_words);
		//parsed.printTextMessageInfo();
		if(num_words > 0)
		{
			text_messages.push_back(parsed);
		}
		parsed.clear();
	}
}

/**
 * This is the readProbabilityFiles function.
 * The function reads the probability files for the spam and ham files and parses them by 
 * total word count 
 * word " " and then word count for spam / ham based on the file
 * The function then parses the info and stores the needed info in a map of <string, TextWords> and vector of <TextWords> 
 * The string is the word itself and TextWords contains details/data about the word
 *
 * @param bool spam_file, determine which file to use, spam or ham
 * @param string probability_file, the probabiliy file for either spam or ham
 * @param uint32_t &num_of_words, total number of words for either spam or ham
 * @param map<string, TextWords> map to contain data from the probabilities file by words and TextWords
 * @param vector<Textwords> &text_words, the data of all of the text words found in the probabilit files.
 * @return none
 *
 * @pre none.
 * @post The function sets up the map and vector to be properly used for the bayesian naive filter afte reading the probability files.
 *
 */
void readProbabilityFiles(bool spam_file, string probability_file, uint32_t &num_of_words, map<string, TextWords> &bayesian_map, vector<TextWords> &text_words)
{
	string push_back;
	string word;
	string num_appear;
	int position;
	ifstream myfile;
	myfile.open(probability_file);
	if(!myfile.is_open())
	{
		cout << "Error Readinng " << probability_file << endl;
		exit(0);
	}
	getline(myfile, push_back);
	unsigned long temp = stoul(push_back, 0, 10);
	num_of_words = temp;
	while(!myfile.eof())
	{
		TextWords training_word;  
		getline(myfile, push_back);
		position = push_back.find(" ");
		word = push_back.substr(0, position);
		training_word.word = word;
		num_appear = push_back.substr(position + 1);
		unsigned long r_temp = stoul(num_appear, 0, 10);
		temp = r_temp;
		if(spam_file)
		{
			//cout << "Num of spam appearances: " << temp << endl;
			training_word.num_appearances_in_spam = temp;
		}
		else
		{
			training_word.num_appearances_in_ham = temp;
		}

		if(bayesian_map.count(training_word.word) == 0)
		{
			bayesian_map.insert(pair<string, TextWords>(training_word.word, training_word));
			text_words.push_back(training_word);
			/*cout << "Word: " << training_word.word << endl;
			//spam_counter = spam_counter + text_words[i].num_appearances_in_spam;
			//ham_counter = ham_counter + text_words[i].num_appearances_in_ham;
			cout << "Appearances: " << training_word.num_appearances << endl;
			cout << "Spam Appearances: " << training_word.num_appearances_in_spam << endl;
			cout << "Ham Appearances: " << training_word.num_appearances_in_ham << endl;
			cout << "Spam Probability: " << setprecision(20) << training_word.probability_of_spam << endl;
			cout << "Ham Probability: " << setprecision(20) << training_word.probability_of_ham << endl << endl;*/
		}
		else if(bayesian_map.count(training_word.word) == 1)
		{
			map<string, TextWords>::iterator find_iterator;
			find_iterator = bayesian_map.find(training_word.word);
			if(find_iterator != bayesian_map.end())
			{
				if(spam_file)
				{
					find_iterator -> second.num_appearances_in_spam = temp;
				}
				else
				{
					find_iterator -> second.num_appearances_in_ham = temp;
				}
				
				for(int i = 0; i < text_words.size(); i++)
				{
					if(training_word.word == text_words[i].word)
					{
						if(spam_file)
						{
							text_words[i].num_appearances_in_spam = temp;
						}
						else
						{
							text_words[i].num_appearances_in_ham = temp;
						}
					}
				}
			}
		}
		else if((bayesian_map.count(training_word.word) == 1 > 1 ))
		{
			cout << "ERROR: Word is Already Mapped!" << endl;
		}
	}
	myfile.close();


}

/**
 * This is the claculateProbabilities function.
 * The function goes through text_messages vector and map and calcuilates the probaiblities for each vector. 
 * The function takes the log of the num_of_appearances in either spam or ham and divides it by total num of either ham or spam words. 
 * The function does this for each word found in the map.
 *
 * @param vector<TextMessages> &text_messages, the vector that contains the textmessages objects based on the training file.
 * @param map<string, Textwords> &bayesian_map, contains the map for all of the individual words in the text_messages.
 * @param uint32_t &num_of_spam_words, total number of spam words
 * @param uint32_t &num_of_ham_words, total number of ham words
 * @return none
 *
 * @pre none.
 * @post The training data probabilities for each word are properly calculated.
 *
 */
void calculateProbabilities(vector<TextWords> &text_words, uint32_t num_of_spam_words, uint32_t num_of_ham_words, map<string, TextWords> &bayesian_map)
{

	for(int i = 0; i < text_words.size(); i++)
	{
		text_words[i].num_appearances = text_words[i].num_appearances_in_spam + text_words[i].num_appearances_in_ham;
		text_words[i].probability_of_spam = log(((double)text_words[i].num_appearances_in_spam / (double)num_of_spam_words) * .45);
		text_words[i].probability_of_ham = log(((double)text_words[i].num_appearances_in_ham / (double)num_of_ham_words) * .55);
		map<string, TextWords>::iterator find_iterator;
		find_iterator = bayesian_map.find(text_words[i].word);
		if(find_iterator != bayesian_map.end())
		{
			find_iterator -> second = text_words[i];
		}
	}
}

/**
 * This is the spamOrHam function.
 * The function goes through text_messages vector and map and calculates the probability of spam and ham for each text message.
 * The function takes the probabilities of the words in the message and adds them. 
 * The function compars the log of the prob of ham and prob of spam of each message and divides them.
 *
 * @param vector<TextMessages> &text_messages, the vector that contains the textmessages objects based on the classify file.
 * @param vector<TextWords> &text_words, the individual words found in the training data set parsed from the probability files
 * @param map<string, Textwords> &bayesian_map, contains the map for all of the individual words in the text_messages.
 * @param uint32_t total words, total words from the training data
 * @param uint32_t num_of_spam_words, total number of spam words
 * @param uint32_t num_of_ham_words, total number of ham words
 * @return none
 *
 * @pre none.
 * @post The training data probabilities for each word are properly calculated.
 *
 */
void spamOrHam(vector<TextMessage> &text_messages, vector<TextWords> &text_words, map<string, TextWords> &bayesian_map, uint32_t total_words, uint32_t num_of_spam_words, uint32_t num_of_ham_words)
{

	for(int i = 0; i < text_messages.size(); i++)
	{
		//cout << "Message: " << text_messages[i].message << endl;
		for(int j = 0; j < text_messages[i].words_in_message.size(); j++)
		{
			map<string, TextWords>::iterator find_iterator;
			find_iterator = bayesian_map.find(text_messages[i].words_in_message[j]);
			if(find_iterator -> second.num_appearances_in_spam >= 1 && find_iterator -> second.num_appearances_in_ham >= 1)
			{
				text_messages[i].prob_of_spam += (find_iterator -> second.probability_of_spam);
				text_messages[i].prob_of_ham += (find_iterator-> second.probability_of_ham);
			}
			else 
			{
				text_messages[i].prob_of_spam += log(1/10000.0);
				text_messages[i].prob_of_ham += log(1/10000.0);
			}
		}
		//text_messages[i].prob_of_spam = log(text_messages[i].prob_of_spam);
		//text_messages[i].prob_of_ham = log(text_messages[i].prob_of_ham);
		text_messages[i].log_ratio = text_messages[i].prob_of_spam/text_messages[i].prob_of_ham;
	}
}







