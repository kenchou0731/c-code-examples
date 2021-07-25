#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

int main(int argc, const char *argv[]) {
	CURL *curl;
	CURLcode res;
	const char *url;
	static const char *post_data = "Hello";

	if (argc == 2) {
		url = argv[1];
	} else {
		url = "https://example.com";
	}

	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data);
 
		/* if we don't provide POSTFIELDSIZE, libcurl will strlen() by
		   itself */
		curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long) strlen(post_data));

		/* Perform the request, res will get the return code */
		res = curl_easy_perform(curl);
		/* Check for errors */
		if (res != CURLE_OK) {
			fprintf(stderr,
				"curl_easy_perform() failed: %s\n",
				curl_easy_strerror(res));
		}

		/* always cleanup */
		curl_easy_cleanup(curl);
	}
	return 0;
}
