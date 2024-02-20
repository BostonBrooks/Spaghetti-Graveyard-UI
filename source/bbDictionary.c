#include "../headers/bbDictionary.h"
#include "../headers/bbFlags.h"
#include "../headers/bbPrintf.h"
#include "../headers/bbSystemIncludes.h"

int32_t hash(unsigned char *str, int32_t n_bins)
{

	uint32_t hash_value = 5381;
	int32_t i = 0;
	int32_t c = str[i];

	while (c != '\0' && c!= '\n') {
		hash_value = hash_value * 33 + c;
		i++;
		c = str[i];

	}

	hash_value %= n_bins;
	return hash_value;
}

bbDictionary* bbDictionary_new (int32_t n_bins){
	bbDictionary* dict = malloc(sizeof(bbDictionary) + n_bins * sizeof(bbDictionary_bin)); //sizeof (bbDictionary) + 2*sizeof (int) * NUM_BINS;?
	assert( dict!= NULL);

	dict->m_Available.Head = F_NONE;
	dict->m_Available.Head = F_NONE;

	for(int32_t i = 0; i < n_bins; i++){
		dict->m_Bins[i].Head = F_NONE;
		dict->m_Bins[i].Tail = F_NONE;
	}

	for (int32_t i = 0; i < 100; i++){
		dict->m_Pool[i] = NULL;
	}

	return dict;
}

int bbDictionary_delete(bbDictionary* dict){
	for (int32_t i = 0; i < 100; i++){
		if (dict->m_Pool[i] != NULL) free (dict->m_Pool[i]);
	}
	free(dict);
}

int bbDictionary_increase(bbDictionary* dict){
	int32_t i = 0;
	while (dict->m_Pool[i] != NULL && i < 100) {
		i++;
	}
	if (i == 100) {
		return F_FULL;
	}

	bbDictionary_entry* entry = calloc(100, sizeof(bbDictionary_entry));
	assert(entry != NULL);
	dict->m_Pool[i] = entry;


	if (dict->m_Available.Head == F_NONE){
		assert(dict->m_Available.Tail == F_NONE);

		for (int32_t l = 0; l < 100; l++){
			dict->m_Pool[i][l].m_Self = i * 100 + l;
			dict->m_Pool[i][l].m_Prev = i * 100 + l - 1;
			dict->m_Pool[i][l].m_Next = i * 100 + l + 1;
			dict->m_Pool[i][l].m_InUse = 0;

		}


		dict->m_Pool[i][0].m_Prev = F_NONE;
        dict->m_Pool[i][100 - 1].m_Next = F_NONE;

		dict->m_Available.Head = i * 100;
        dict->m_Available.Head = (i+1) * 100 - 1;

		return F_SUCCESS;
	}

	bbDebug("Why are you increasing the pool when it's not empty?\n");
}

bbDictionary_entry* bbDictionary_indexLookup(bbDictionary* dict, int32_t index){
	int32_t level1 = index / 100;
	int32_t level2 = index % 100;
	bbDictionary_entry* entry = &dict->m_Pool[level1][level2];
	assert (entry != NULL);
	//printf("index = %d, self = %d\n", index, entry->Dict_Self);
	return entry;
}

int bbDictionary_lookupIndex(bbDictionary* dict, char* key){
	int32_t hash_value = hash(key, dict->m_NumBins);
	bbDictionary_entry* entry;
	int32_t index = dict->m_Bins[hash_value].Head;

	while (index != F_NONE) {
		entry = bbDictionary_index_lookup(dict, index);
		if(strcmp(key, entry->m_Key) == 0) return index;
		index = entry->m_Next;
	}

	return F_NONE;
}

int bbDictionary_lookup(bbDictionary* dict, char* key){
	int index = bbDictionary_lookupIndex(dict, key);
	if (index == F_NONE) return F_NONE;
	bbDictionary_entry* entry = bbDictionary_indexLookup(dict, index);
	return entry->m_Value;
}

