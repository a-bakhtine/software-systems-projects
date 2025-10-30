#include <stdio.h>
#include <stdlib.h>
#include "stringbuilder.h" // right way to include?

// global variable def 
char *ptr; // pointer to the underlying, fized-size arr that actually holds the data
int capacity; // the total size of the fized-size array
int size; // the count of items currently storedi nside the underlying arr

// helper to copy string
void my_strcopy(char *dest, char const *source, int len)
{
	for (int i = 0; i < len && source[i] != '\0'; i++) {
		dest[i] = source[i];
	}
}

/** Initializes the stringbuilder, allocating an underlying array of the given `capacity`. The
 *  initial size of the stringbuilder is zero. */
void sb_init(int given_capacity) {
	ptr = malloc(capacity * sizeof(char));
	capacity = given_capacity;
	size = 0;
}

/** Appends characters from `buf` to the end of the stringbuilder, until either a NUL byte is
 *  reached or `len` many characters have been copied. */
void sb_append(char const *buf, int len) 
{
	// check size
	if (size + len > capacity) {
		while (size + len > capacity) {
			capacity *= 2;
		}	

		// ptr w/ new size
		char *new_ptr = malloc(capacity * sizeof(char));
		// copy data from ptr to new ptr
		my_strcopy(new_ptr, ptr, size);
		free(ptr);
		// set ptr to new ptr
		ptr = new_ptr;
	}
	// append string to end of pointer
	my_strcopy(ptr + size, buf, len);
	size += len;	
	
}
/** Obtains a copy of the current contents of the stringbuilder as a malloc'd, null-terminated
 *  string. It becomes the responsibility of the caller to call `free` on that string. */
char * sb_build()
{
	char *build = malloc((size+1) * sizeof(char));
	my_strcopy(build, ptr, size);
	build[size] = '\0'; // terminate string
	return build;
}

/** Releases the memory held by the stringbuilder.
 *  It is possible to call `sb_init` again after this to build another string. */
void sb_destroy() 
{
	free(ptr);
	ptr = NULL;
	capacity = 0;
	size = 0;
}

// main
int main() {
	sb_init(8);

	sb_append("Append ", 7);
	sb_append("Me! ", 4);
	sb_append("And all of me!", 14);

	char* build = sb_build();
	printf("Built String: %s\n", build);
	
	sb_destroy();

	sb_init(8);
	
	sb_append("Test ", 5);
	sb_append("Meowt", 5);

	char* build2 = sb_build();
	printf("Built String2: %s\n", build2);
	
	sb_destroy();
	return 0;
}
