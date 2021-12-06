#include "bench.h"

namespace sqliteBench {
  
  // #1. Write a code for setting the journal mode in the SQLite database engine
  // [Requirement]
  // (1) This function set jounral mode using "FLAGS_journal_mode" extern variable (user input)
  // (2) This function check journal mode; if user try to set wrong journal mode then return -2
  // (3) This function returns status (int data type) of sqlite API function
  int Benchmark::benchmark_setJournalMode() {
	  int status;
	  char* err_msg = NULL;
	  if(!strcmp("off", FLAGS_journal_mode)){
		  const char* OFF_stmt = "PRAGMA journal_mode = OFF";
		  status = sqlite3_exec(db_, OFF_stmt, NULL, NULL, &err_msg);
	  }
	  else if(!strcmp("wal", FLAGS_journal_mode)){
		  const char* WAL_stmt = "PRAGMA journal_mode = WAL";
		  status = sqlite3_exec(db_, WAL_stmt, NULL, NULL, &err_msg);
	  }
	  else if(!strcmp("del", FLAGS_journal_mode)){
		  const char* DEL_stmt = "PRAGMA journal_mode = DEL";
		  status = sqlite3_exec(db_, DEL_stmt, NULL, NULL, &err_msg);
	  }
	  else
		  return -2;
	// I used exec API function for configure journal mode and I used strcmp function to check the journal name
	  return status;

    // please fill this function
  }

  // #2. Write a code for setting page size in the SQLite database engine
  // [Requirement]
  // (1) This function set page size using "FLAGS_page_size" extern variable (user input)
  // (2) This function return status (int data type) of sqltie API function
  // (3) This function is called at benchmark_open() in bench.cc
  int Benchmark::benchmark_setPageSize() {
	  int status;
	  char* err_msg = NULL;
	  char page_size[100];
	  snprintf(page_size, sizeof(page_size), "PRAGMA page_size = %d", FLAGS_page_size);
	  status = sqlite3_exec(db_, page_size, NULL, NULL, &err_msg);
	  // I used exec API function for configurate page size
    // please fill this function
    return status;

  }

  // #3. Write a code for insert function (direct SQL execution mode)
  // [Requriement]
  // (1) This function fill random key-value data using direct qurey execution sqlite API function
  //     (please refer to lecture slide week 11)
  // (2) This function has single arguemnt num_ which is total number of operations
  // (3) This function create SQL statement (key-value pair) do not modfiy this code 
  // (4) This function execute given SQL statement
  // (5) This function is called at benchmark_open() in bench.cc
  int Benchmark::benchmark_directFillRand(int num_) {
    //      DO NOT MODIFY HERE     //
    const char* value = gen_.rand_gen_generate(FLAGS_value_size);
    char key[100];
    const int k = gen_.rand_next() % num_;

    snprintf(key, sizeof(key), "%016d", k);
    char fill_stmt[100];
    snprintf(fill_stmt, sizeof(fill_stmt), "INSERT INTO test values (%s , x'%x')", key ,value);
    ////////////////////////////////
    int status;
    char* err_msg = NULL;
    status = sqlite3_exec(db_, fill_stmt, NULL, NULL, &err_msg);
    // I used exec API function for excute sql statement (Insert)

    // execute SQL statement
    // please fill this function
    return status;
  }

}; // namespace sqliteBench

