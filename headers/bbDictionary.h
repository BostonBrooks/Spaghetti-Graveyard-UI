/**
 * @file
 * @brief bbDictionary stores a number of key-value pairs for fast lookup.
 * Keys should be up to 32 characters. dictionary can contain up to 10000 members
 */

#ifndef BBDICTIONARY_H
#define BBDICTIONARY_H

#include "../headers/bbSystemIncludes.h"

typedef struct {
	int32_t Head;
	int32_t Tail;
} bbDictionary_bin;

typedef struct {

	int32_t m_Self;
	int32_t m_Prev;
	int32_t m_Next;
	int32_t m_InUse;

	char m_Key[33];
	int32_t m_Value;

} bbDictionary_entry;

typedef struct {

	int32_t m_NumBins;
	bbDictionary_entry* m_Pool[100];
	bbDictionary_bin m_Available;
	bbDictionary_bin m_Bins[];

} bbDictionary;

/// create a new dictionary
bbDictionary* bbDictionary_new(int32_t n_bins);
/// delete an existing dictionary
int32_t bbDictionary_delete(bbDictionary* dict);
/// add key/value pair to dictionary
int32_t bbDictionary_add(bbDictionary* dict, char* key, int value);  //and overwrite if duplicate
/// remove a key from dictionary
int32_t bbDictionary_remove(bbDictionary* dict, char* key);
/// lookup a key in dictionary
int32_t bbDictionary_lookup(bbDictionary* dict, char* key);
/// remove all key/value pairs in dicitonary
int32_t bbDictionary_clear(bbDictionary* dict);
/// print all data in dictionary
int32_t bbDictionary_print(bbDictionary* dict);


#endif //BBDICTIONARY_H