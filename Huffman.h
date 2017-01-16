/**
 * @author Yuhei Horibe
 * Data compression algorithm via Huffman Tree *
 **/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

#include "DataProcessor.h"

// Huffman Tree Node
class Huffman_Node{
private:
	std::string	m_key;		// Key of Data
	uint32_t	m_uFreq;	// Frequency

	// References
	std::unique_ptr<Huffman_Node>	m_rNode;
	std::unique_ptr<Huffman_Node>	m_lNode;

public:
	// Concatination
	Huffman_Node(std::unique_ptr<Huffman_Node> rNode, std::unique_ptr<Huffman_Node> lNode);

	// Normal constructor
	Huffman_Node(std::string key, uint32_t m_uFreq);

	// Acccessor
	std::string		GetKey();
	uint32_t		GetFreq();

	~Huffman_Node();
};

// Huffman Tree Node Manager
class Huffman_Comp : public DataCompressionManager{
private:
	std::vector<std::pair<std::string, uint32_t> >	m_freqTable;
	std::unique_ptr<Huffman_Node>						m_huffmanTree;

	// Count the frequency of the key.
	void	count(std::string key);

	// Build the Huffman tree.
	bool	build_HuffmanTree();

public:
	// Inherit the constructors
	Huffman_Comp(std::string fileName) : DataCompressionManager(std::string fileName);
	Huffman_Comp() : DataCompressionManager();

	// Compression function
	bool	StartCompression();

};

