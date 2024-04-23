// THIS IS THE PROVIDED CODE FOR PROGRAM #3, DSA 1, FALL 2023

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

// A simple class; each object holds four public fields
class Data {
public:
  string lastName;
  string firstName;
  string ssn;
};

// Load the data from a specified input file
void loadDataList(list<Data *> &l, const string &filename) {

  ifstream input(filename);
  if (!input) {
    cerr << "Error: could not open " << filename << "\n";
    exit(1);
  }

  // The first line indicates the size
  string line;
  getline(input, line);
  stringstream ss(line);
  int size;
  ss >> size;

  // Load the data
  for (int i = 0; i < size; i++) {
    getline(input, line);
    stringstream ss2(line);
    Data *pData = new Data();
    ss2 >> pData->lastName >> pData->firstName >> pData->ssn;
    l.push_back(pData);
  }

  input.close();
}

// Output the data to a specified output file
void writeDataList(const list<Data *> &l, const string &filename) {

  ofstream output(filename);
  if (!output) {
    cerr << "Error: could not open " << filename << "\n";
    exit(1);
  }

  // Write the size first
  int size = l.size();
  output << size << "\n";

  // Write the data
  for (auto pData:l) {
    output << pData->lastName << " " 
	   << pData->firstName << " " 
	   << pData->ssn << "\n";
  }

  output.close();
}

// Sort the data according to a specified field
// (Implementation of this function will be later in this file)
void sortDataList(list<Data *> &);

// The main function calls routines to get the data, sort the data,
// and output the data. The sort is timed according to CPU time.
int main() {
  string filename;
  cout << "Enter name of input file: ";
  cin >> filename;
  list<Data *> theList;
  loadDataList(theList, filename);
    cout << "Data loaded. Size of the list: " << theList.size() << endl;

  cout << "Executing sort...\n";
  clock_t t1 = clock();
  sortDataList(theList);
  clock_t t2 = clock();
  double timeDiff = ((double) (t2 - t1)) / CLOCKS_PER_SEC;

  cout << "Sort finished. CPU time was " << timeDiff << " seconds.\n";

  cout << "Enter name of output file: ";
  cin >> filename;
  writeDataList(theList, filename);

  return 0;
}

// -------------------------------------------------
// YOU MAY NOT CHANGE OR ADD ANY CODE ABOVE HERE !!!
// -------------------------------------------------

// You may add global variables, functions, and/or
// class defintions here if you wish.
// Helper function to get the character at 'index' in a string
#include <unordered_map>

unordered_map<string, int> FirstNameMap = {
    {"ZACHARY", 493},
    {"WILLOW", 488},
    {"WILLIAM", 487},
    {"WESTON", 486},
    {"WESLEY", 485},
    {"VIOLET", 482},
    {"VICTORIA", 480},
    {"VALERIA", 476},
    {"TYLER", 474},
    {"TIMOTHY", 470},
    {"SYDNEY", 463},
    {"SLOANE", 456},
    {"SILAS", 454},
    {"SARA", 444},
    {"SANTIAGO", 443},
    {"SAMUEL", 442},
    {"RYLEE", 438},
    {"RYKER", 437},
    {"ZAYDEN", 496},
    {"RYDER", 436},
    {"RYAN", 435},
    {"SEBASTIAN", 450},
    {"ROSE", 431},
    {"ROSALIE", 430},
    {"ROMAN", 429},
    {"RIVER", 427},
    {"VANESSA", 478},
    {"RILEY", 426},
    {"REMI", 422},
    {"RAELYNN", 418},
    {"WAYLON", 484},
    {"RACHEL", 417},
    {"QUINN", 416},
    {"PRESTON", 415},
    {"PIPER", 413},
    {"PENELOPE", 410},
    {"PAUL", 407},
    {"PARKER", 405},
    {"TESSA", 466},
    {"PAISLEY", 403},
    {"PAIGE", 402},
    {"OSCAR", 400},
    {"XIMENA", 492},
    {"OLIVIA", 398},
    {"SAMANTHA", 441},
    {"NOVA", 396},
    {"NORAH", 395},
    {"STEVEN", 461},
    {"NOLAN", 393},
    {"NOELLE", 392},
    {"NICOLE", 390},
    {"VALENTINA", 475},
    {"NICOLAS", 389},
    {"NEVAEH", 387},
    {"SOPHIA", 458},
    {"NATHAN", 385},
    {"NATALIE", 384},
    {"NAOMI", 382},
    {"MOLLY", 378},
    {"MILA", 375},
    {"MIGUEL", 374},
    {"MICAH", 371},
    {"MIA", 370},
    {"MELODY", 368},
    {"MAYA", 365},
    {"MAXIMUS", 363},
    {"MAVERICK", 361},
    {"MATTHEW", 360},
    {"MATTEO", 359},
    {"MATIAS", 358},
    {"MATEO", 357},
    {"MASON", 356},
    {"MARY", 355},
    {"MARLEY", 354},
    {"MARIA", 351},
    {"MARGARET", 350},
    {"THIAGO", 468},
    {"MALIA", 348},
    {"MADISON", 344},
    {"MADELINE", 342},
    {"MYLES", 381},
    {"MADDOX", 341},
    {"MACKENZIE", 340},
    {"LYLA", 339},
    {"LUNA", 337},
    {"LUIS", 334},
    {"MARIAH", 352},
    {"LUCY", 333},
    {"SIENNA", 453},
    {"LUCIA", 332},
    {"LUCAS", 331},
    {"LUCA", 330},
    {"LORENZO", 329},
    {"LONDYN", 328},
    {"REAGAN", 419},
    {"LUKE", 336},
    {"LONDON", 327},
    {"LOLA", 326},
    {"LOGAN", 325},
    {"LINCOLN", 324},
    {"LILY", 323},
    {"LEVI", 317},
    {"SELENA", 451},
    {"LEO", 314},
    {"LEILANI", 313},
    {"LEILA", 312},
    {"MAX", 362},
    {"LEAH", 311},
    {"VINCENT", 481},
    {"LAYLA", 310},
    {"LAUREN", 309},
    {"LANDON", 308},
    {"RUBY", 434},
    {"KYLIE", 305},
    {"KYLE", 304},
    {"KNOX", 303},
    {"KINGSTON", 301},
    {"KIMBERLY", 299},
    {"PATRICK", 406},
    {"KILLIAN", 298},
    {"KHLOE", 297},
    {"KENNEDY", 294},
    {"SOFIA", 457},
    {"KAYLEE", 292},
    {"LEON", 315},
    {"KAYLA", 291},
    {"RICHARD", 425},
    {"KATHERINE", 289},
    {"NATHANIEL", 386},
    {"KARTER", 288},
    {"KALEB", 287},
    {"KADEN", 284},
    {"JULIETTE", 281},
    {"JULIET", 280},
    {"JULIANNA", 279},
    {"JULIANA", 278},
    {"JULIAN", 277},
    {"MICHELLE", 373},
    {"JULIA", 276},
    {"OLIVER", 397},
    {"JUDAH", 274},
    {"JOSUE", 272},
    {"JOSHUA", 269},
    {"JOSEPHINE", 268},
    {"ROBERT", 428},
    {"JORGE", 265},
    {"JORDAN", 263},
    {"JONATHAN", 262},
    {"VIVIAN", 483},
    {"JONAH", 261},
    {"ZANDER", 494},
    {"JOHN", 260},
    {"KENNETH", 295},
    {"ADALYN", 6},
    {"CHLOE", 119},
    {"BRYSON", 99},
    {"LIAM", 318},
    {"AXEL", 70},
    {"JACK", 234},
    {"CHARLOTTE", 117},
    {"XAVIER", 491},
    {"EVERLY", 183},
    {"CHARLIE", 116},
    {"ZION", 497},
    {"PEYTON", 412},
    {"CATHERINE", 111},
    {"REMINGTON", 423},
    {"CAMERON", 105},
    {"BRIELLE", 90},
    {"GENESIS", 195},
    {"JEREMY", 253},
    {"JOSEPH", 267},
    {"GRAYSON", 205},
    {"NATALIA", 383},
    {"JASMINE", 242},
    {"CALVIN", 103},
    {"ABIGAIL", 3},
    {"CALEB", 101},
    {"JACE", 233},
    {"HENRY", 218},
    {"ERIC", 176},
    {"CLAIRE", 122},
    {"ADELINE", 10},
    {"CHRISTOPHER", 121},
    {"BRODY", 91},
    {"ADAM", 8},
    {"TUCKER", 473},
    {"BRIAN", 88},
    {"MILO", 377},
    {"COLIN", 126},
    {"DAKOTA", 132},
    {"BRIANNA", 89},
    {"VICTOR", 479},
    {"BRANDON", 84},
    {"BROOKE", 92},
    {"DOMINIC", 147},
    {"KEVIN", 296},
    {"BRADY", 83},
    {"RYLEIGH", 439},
    {"BRADLEY", 82},
    {"BLAKE", 81},
    {"BENJAMIN", 78},
    {"OWEN", 401},
    {"ARIANA", 51},
    {"BECKETT", 76},
    {"MALACHI", 347},
    {"GREYSON", 206},
    {"JUNE", 282},
    {"CARLOS", 107},
    {"BARRETT", 74},
    {"BAILEY", 73},
    {"CECILIA", 113},
    {"DELANEY", 141},
    {"TRISTAN", 472},
    {"SCARLETT", 449},
    {"AVERY", 69},
    {"BROOKLYNN", 94},
    {"ALEJANDRO", 20},
    {"ARTHUR", 54},
    {"EVELYN", 181},
    {"BENNETT", 79},
    {"CORA", 130},
    {"GABRIELLA", 192},
    {"AURORA", 64},
    {"ELENA", 153},
    {"AUGUST", 63},
    {"CAROLINE", 108},
    {"BENTLEY", 80},
    {"AUBREY", 61},
    {"ROWAN", 433},
    {"ATHENA", 59},
    {"KENDALL", 293},
    {"JESSE", 254},
    {"ELLIE", 163},
    {"ELISE", 158},
    {"BRYAN", 96},
    {"ALEXIS", 25},
    {"CHRISTIAN", 120},
    {"EMERSYN", 168},
    {"BEAU", 75},
    {"ALEX", 21},
    {"MAGGIE", 345},
    {"JOSIAH", 270},
    {"GAEL", 193},
    {"ANDRES", 40},
    {"SADIE", 440},
    {"GRACE", 201},
    {"DECLAN", 140},
    {"MYA", 380},
    {"CLAYTON", 124},
    {"JUSTIN", 283},
    {"ALAYNA", 19},
    {"BRANTLEY", 85},
    {"ELOISE", 166},
    {"ZANE", 495},
    {"COLE", 125},
    {"SARAH", 445},
    {"EMILIANO", 171},
    {"AMAYA", 33},
    {"ALICE", 26},
    {"ISAAC", 224},
    {"AMIR", 35},
    {"IRIS", 223},
    {"JOSE", 266},
    {"ALEXA", 22},
    {"GRANT", 204},
    {"OMAR", 399},
    {"ADELYN", 11},
    {"MCKENZIE", 366},
    {"AUBREE", 60},
    {"REBECCA", 420},
    {"MILES", 376},
    {"KAYDEN", 290},
    {"CLARA", 123},
    {"ELLA", 161},
    {"ALAINA", 16},
    {"NORA", 394},
    {"ABEL", 2},
    {"CHASE", 118},
    {"ALINA", 27},
    {"ANGEL", 42},
    {"AALIYAH", 0},
    {"CONNOR", 128},
    {"FINN", 189},
    {"WYATT", 489},
    {"MADELYN", 343},
    {"LAILA", 307},
    {"AYDEN", 71},
    {"ABRAHAM", 4},
    {"AARON", 1},
    {"HARMONY", 212},
    {"ARIA", 50},
    {"PETER", 411},
    {"CHARLES", 114},
    {"BROOKLYN", 93},
    {"LILA", 319},
    {"ALIVIA", 28},
    {"IAN", 222},
    {"AUDREY", 62},
    {"ALEXANDER", 23},
    {"BELLA", 77},
    {"DAWSON", 138},
    {"TAYLOR", 464},
    {"BRAXTON", 86},
    {"ANA", 37},
    {"ANASTASIA", 38},
    {"JAXON", 247},
    {"ALIYAH", 29},
    {"KAI", 285},
    {"AMARA", 32},
    {"LYDIA", 338},
    {"JESUS", 256},
    {"ISABELLA", 226},
    {"ADRIAN", 12},
    {"BROOKS", 95},
    {"EMILIA", 170},
    {"LILLY", 322},
    {"AMELIA", 34},
    {"AMY", 36},
    {"ELLIOT", 164},
    {"AUSTIN", 65},
    {"MESSIAH", 369},
    {"ADRIANA", 13},
    {"MAKAYLA", 346},
    {"ASHER", 56},
    {"ANNA", 45},
    {"ANNABELLE", 46},
    {"CAYDEN", 112},
    {"SOPHIE", 459},
    {"REESE", 421},
    {"JUAN", 273},
    {"ELLIANA", 162},
    {"CARSON", 109},
    {"ALLISON", 30},
    {"EVA", 179},
    {"JOSIE", 271},
    {"ANTONIO", 48},
    {"SAWYER", 448},
    {"CALLIE", 102},
    {"ALYSSA", 31},
    {"STELLA", 460},
    {"ANTHONY", 47},
    {"JAXSON", 248},
    {"ETHAN", 178},
    {"ARABELLA", 49},
    {"ARIANNA", 52},
    {"EDEN", 150},
    {"ALEXANDRA", 24},
    {"ARIEL", 53},
    {"PAXTON", 408},
    {"AIDEN", 15},
    {"ELIJAH", 157},
    {"MICHAEL", 372},
    {"ELIZABETH", 160},
    {"JOANNA", 257},
    {"ARYA", 55},
    {"ISABEL", 225},
    {"ASHLEY", 57},
    {"JADEN", 238},
    {"COOPER", 129},
    {"SKYLAR", 455},
    {"DAISY", 131},
    {"KAIDEN", 286},
    {"DAMIAN", 134},
    {"DANIELA", 136},
    {"PAYTON", 409},
    {"DAVID", 137},
    {"DEAN", 139},
    {"VALERIE", 477},
    {"ANDREA", 39},
    {"JEREMIAH", 252},
    {"ALAN", 17},
    {"DELILAH", 142},
    {"DEREK", 143},
    {"ANDREW", 41},
    {"EMMANUEL", 174},
    {"DESTINY", 144},
    {"KYRIE", 306},
    {"GIOVANNI", 200},
    {"JASPER", 244},
    {"LEONARDO", 316},
    {"DIANA", 145},
    {"DIEGO", 146},
    {"NOAH", 391},
    {"JADE", 237},
    {"KING", 300},
    {"DYLAN", 148},
    {"SUMMER", 462},
    {"SERENITY", 452},
    {"BRAYDEN", 87},
    {"EZEKIEL", 184},
    {"JAMESON", 241},
    {"EASTON", 149},
    {"CAMDEN", 104},
    {"EDWARD", 151},
    {"ELI", 154},
    {"ISLA", 229},
    {"ELIANA", 155},
    {"ELIAS", 156},
    {"ELIZA", 159},
    {"LILIANA", 320},
    {"EMERY", 169},
    {"EMERSON", 167},
    {"COLTON", 127},
    {"IVAN", 231},
    {"ZOEY", 499},
    {"ALANA", 18},
    {"EMILY", 172},
    {"EMMA", 173},
    {"EMMETT", 175},
    {"ESTHER", 177},
    {"THEODORE", 467},
    {"JORDYN", 264},
    {"EVAN", 180},
    {"JOEL", 259},
    {"EVERETT", 182},
    {"GRAHAM", 203},
    {"HUDSON", 220},
    {"AYLA", 72},
    {"EZRA", 185},
    {"ELEANOR", 152},
    {"GABRIEL", 191},
    {"JAYCE", 249},
    {"CARTER", 110},
    {"FAITH", 186},
    {"ADALINE", 5},
    {"FELIX", 187},
    {"JASON", 243},
    {"FIONA", 190},
    {"ANGELA", 43},
    {"HARPER", 213},
    {"SAVANNAH", 446},
    {"RHETT", 424},
    {"GENEVIEVE", 196},
    {"AVA", 67},
    {"GEORGE", 197},
    {"PRESLEY", 414},
    {"GEORGIA", 198},
    {"GIANNA", 199},
    {"CADEN", 100},
    {"GRACIE", 202},
    {"AIDAN", 14},
    {"GRIFFIN", 207},
    {"ZOE", 498},
    {"ADALYNN", 7},
    {"FINLEY", 188},
    {"HADLEY", 208},
    {"ANGELINA", 44},
    {"HUNTER", 221},
    {"MORGAN", 379},
    {"MARK", 353},
    {"HAILEY", 209},
    {"TRINITY", 471},
    {"ELLIOTT", 165},
    {"HANNAH", 210},
    {"JAVIER", 245},
    {"HARLEY", 211},
    {"MAXWELL", 364},
    {"HARRISON", 214},
    {"HAYDEN", 216},
    {"TEAGAN", 465},
    {"HAZEL", 217},
    {"THOMAS", 469},
    {"BRYNLEE", 98},
    {"HOLDEN", 219},
    {"JUDE", 275},
    {"ISABELLE", 227},
    {"DALEYZA", 133},
    {"DANIEL", 135},
    {"ISAIAH", 228},
    {"LILLIAN", 321},
    {"BRYCE", 97},
    {"ISRAEL", 230},
    {"NICHOLAS", 388},
    {"IVY", 232},
    {"XANDER", 490},
    {"CAMILA", 106},
    {"JACKSON", 235},
    {"LUKAS", 335},
    {"ASHTON", 58},
    {"GAVIN", 194},
    {"JACOB", 236},
    {"MELANIE", 367},
    {"JAKE", 239},
    {"JAMES", 240},
    {"JAX", 246},
    {"JAYDEN", 250},
    {"AUTUMN", 66},
    {"JAYLA", 251},
    {"KINSLEY", 302},
    {"ADDISON", 9},
    {"JESSICA", 255},
    {"MARCUS", 349},
    {"JOCELYN", 258},
};

unordered_map<string, int> LastNameMap = {
    {"ZHANG", 498},
    {"WU", 495},
    {"WOODS", 493},
    {"WOOD", 492},
    {"WISE", 488},
    {"WILLIS", 486},
    {"WELLS", 480},
    {"WELCH", 479},
    {"WEBSTER", 478},
    {"WEBER", 477},
    {"WEBB", 476},
    {"WEAVER", 475},
    {"WATKINS", 472},
    {"WATERS", 471},
    {"WARREN", 469},
    {"WARNER", 468},
    {"WANG", 466},
    {"WALTON", 465},
    {"WALLACE", 462},
    {"WAGNER", 460},
    {"WADE", 459},
    {"WALKER", 461},
    {"VELASQUEZ", 458},
    {"VEGA", 457},
    {"VASQUEZ", 454},
    {"VALENCIA", 452},
    {"VALDEZ", 451},
    {"TURNER", 450},
    {"TRAN", 447},
    {"TORRES", 445},
    {"THOMAS", 441},
    {"SUTTON", 436},
    {"SULLIVAN", 435},
    {"STRICKLAND", 434},
    {"STONE", 433},
    {"STEWART", 432},
    {"STEVENS", 430},
    {"ZIMMERMAN", 499},
    {"STEPHENS", 429},
    {"SPENCER", 426},
    {"TODD", 444},
    {"SOTO", 425},
    {"STEVENSON", 431},
    {"SINGH", 421},
    {"SIMPSON", 419},
    {"SHAW", 413},
    {"SIMMONS", 417},
    {"SHARP", 412},
    {"SERRANO", 411},
    {"SCHNEIDER", 406},
    {"SANTIAGO", 402},
    {"SANDOVAL", 401},
    {"SALAZAR", 397},
    {"RYAN", 396},
    {"RUSSELL", 395},
    {"ROSS", 392},
    {"WALSH", 463},
    {"ROSE", 391},
    {"ROMERO", 389},
    {"ROJAS", 387},
    {"TATE", 438},
    {"ROGERS", 386},
    {"RODRIGUEZ", 385},
    {"RODGERS", 384},
    {"RIVAS", 377},
    {"RIOS", 376},
    {"RICHARDS", 373},
    {"RICE", 372},
    {"RHODES", 371},
    {"REYNOLDS", 370},
    {"TRUJILLO", 448},
    {"REESE", 366},
    {"RAY", 364},
    {"RAMOS", 362},
    {"RAMIREZ", 361},
    {"QUINN", 360},
    {"PRICE", 359},
    {"POWERS", 358},
    {"ROBLES", 383},
    {"POWELL", 357},
    {"POTTER", 356},
    {"PIERCE", 354},
    {"PHAM", 352},
    {"PEREZ", 346},
    {"THOMPSON", 442},
    {"PENA", 345},
    {"PATTERSON", 341},
    {"PARSONS", 339},
    {"PAGE", 334},
    {"OWENS", 331},
    {"ORTEGA", 329},
    {"ROMAN", 388},
    {"OLSON", 328},
    {"OCONNOR", 326},
    {"OBRIEN", 324},
    {"NORMAN", 321},
    {"NELSON", 316},
    {"NEAL", 315},
    {"NAVARRO", 314},
    {"MURRAY", 312},
    {"MURPHY", 311},
    {"MUNOZ", 310},
    {"MULLINS", 309},
    {"MOSS", 308},
    {"REEVES", 367},
    {"MORRISON", 307},
    {"PAYNE", 343},
    {"MORRIS", 306},
    {"MORGAN", 305},
    {"MORENO", 304},
    {"MOORE", 301},
    {"WOLF", 489},
    {"WASHINGTON", 470},
    {"MONTGOMERY", 299},
    {"MITCHELL", 297},
    {"MIRANDA", 296},
    {"MEYER", 292},
    {"WILLIAMS", 484},
    {"MENDOZA", 291},
    {"MEJIA", 289},
    {"MENDEZ", 290},
    {"MEDINA", 288},
    {"MCKINNEY", 286},
    {"MCGEE", 285},
    {"MCDONALD", 284},
    {"MCDANIEL", 283},
    {"MCCOY", 282},
    {"MAY", 280},
    {"MARTINEZ", 276},
    {"PAUL", 342},
    {"MARTIN", 275},
    {"MARSHALL", 274},
    {"MARQUEZ", 273},
    {"MANNING", 272},
    {"WARD", 467},
    {"MALONE", 270},
    {"RAMSEY", 363},
    {"LYNCH", 266},
    {"LUNA", 265},
    {"LOWE", 263},
    {"LOVE", 262},
    {"LOPEZ", 261},
    {"NORRIS", 322},
    {"LOGAN", 259},
    {"ESTRADA", 123},
    {"FRAZIER", 144},
    {"HOPKINS", 211},
    {"STEELE", 428},
    {"ESPINOZA", 122},
    {"SNYDER", 423},
    {"MAXWELL", 279},
    {"HARRISON", 192},
    {"FREEMAN", 145},
    {"CURTIS", 98},
    {"SCHMIDT", 405},
    {"DOUGLAS", 113},
    {"ELLIOTT", 119},
    {"SIMS", 420},
    {"DIXON", 111},
    {"GILL", 158},
    {"DAVIS", 102},
    {"DANIEL", 99},
    {"FLORES", 135},
    {"ERICKSON", 121},
    {"DAY", 104},
    {"REID", 368},
    {"CRUZ", 94},
    {"GRIFFITH", 173},
    {"DENNIS", 109},
    {"PARKER", 337},
    {"CORTEZ", 89},
    {"COOPER", 88},
    {"WEST", 481},
    {"DAWSON", 103},
    {"PEARSON", 344},
    {"COOK", 87},
    {"COLON", 85},
    {"MASON", 277},
    {"COLEMAN", 83},
    {"COHEN", 81},
    {"LIU", 258},
    {"CERVANTES", 70},
    {"GRAY", 168},
    {"CLARKE", 80},
    {"CLARK", 79},
    {"BELL", 29},
    {"SCOTT", 410},
    {"CHANG", 74},
    {"MYERS", 313},
    {"INGRAM", 221},
    {"BLAIR", 35},
    {"WATSON", 473},
    {"CHAMBERS", 71},
    {"WOLFE", 490},
    {"CROSS", 93},
    {"CASTILLO", 68},
    {"ROSALES", 390},
    {"ALVAREZ", 8},
    {"FULLER", 147},
    {"LEONARD", 253},
    {"BLACK", 34},
    {"NEWMAN", 317},
    {"FIELDS", 128},
    {"RILEY", 375},
    {"CARRILLO", 64},
    {"DIAZ", 110},
    {"ANDERSON", 9},
    {"BARKER", 21},
    {"DELGADO", 108},
    {"CARR", 63},
    {"CARPENTER", 62},
    {"GRAVES", 167},
    {"TERRY", 440},
    {"JOHNSON", 229},
    {"CARLSON", 61},
    {"YANG", 496},
    {"TUCKER", 449},
    {"FIGUEROA", 129},
    {"BECK", 27},
    {"BARTON", 25},
    {"CHAVEZ", 76},
    {"FARMER", 125},
    {"HILL", 204},
    {"CHEN", 77},
    {"BURKE", 47},
    {"CHAN", 72},
    {"HAMMOND", 183},
    {"BARNETT", 23},
    {"BARNES", 22},
    {"SIMON", 418},
    {"GARCIA", 150},
    {"PETERSON", 351},
    {"HUBBARD", 216},
    {"SANDERS", 400},
    {"DEAN", 105},
    {"SCHWARTZ", 409},
    {"LAWSON", 249},
    {"CARTER", 66},
    {"ROBINSON", 382},
    {"DAVIDSON", 101},
    {"SCHULTZ", 408},
    {"PACHECO", 332},
    {"BARBER", 20},
    {"FERGUSON", 126},
    {"AUSTIN", 13},
    {"GOMEZ", 159},
    {"TAYLOR", 439},
    {"MILLS", 295},
    {"ACOSTA", 0},
    {"LE", 250},
    {"CUNNINGHAM", 96},
    {"GARRETT", 153},
    {"MILES", 293},
    {"BERRY", 32},
    {"EDWARDS", 118},
    {"BISHOP", 33},
    {"DELEON", 107},
    {"BANKS", 19},
    {"BAILEY", 16},
    {"CANNON", 59},
    {"SWANSON", 437},
    {"ADAMS", 1},
    {"WHITE", 483},
    {"SHERMAN", 415},
    {"BRADLEY", 40},
    {"FITZGERALD", 132},
    {"SILVA", 416},
    {"DOMINGUEZ", 112},
    {"PERKINS", 347},
    {"NEWTON", 318},
    {"BAKER", 17},
    {"BRYANT", 45},
    {"CALDERON", 54},
    {"JAMES", 224},
    {"DANIELS", 100},
    {"HAMPTON", 184},
    {"NGUYEN", 319},
    {"ALEXANDER", 5},
    {"PARK", 336},
    {"CHAPMAN", 75},
    {"DELACRUZ", 106},
    {"PALMER", 335},
    {"NUNEZ", 323},
    {"JONES", 231},
    {"MILLER", 294},
    {"BECKER", 28},
    {"JOSEPH", 233},
    {"MORALES", 302},
    {"LIN", 256},
    {"BURTON", 49},
    {"ALLEN", 6},
    {"VAUGHN", 455},
    {"AGUILAR", 3},
    {"HALL", 181},
    {"WONG", 491},
    {"ELLIS", 120},
    {"CASTRO", 69},
    {"WALTERS", 464},
    {"PERRY", 348},
    {"BARRETT", 24},
    {"COX", 90},
    {"BURGESS", 46},
    {"HAWKINS", 195},
    {"STANLEY", 427},
    {"OCHOA", 325},
    {"DUNCAN", 115},
    {"ARMSTRONG", 11},
    {"CAMPOS", 58},
    {"FORD", 136},
    {"RUIZ", 394},
    {"HORTON", 212},
    {"OLIVER", 327},
    {"HUNT", 219},
    {"PADILLA", 333},
    {"FISHER", 131},
    {"BENSON", 31},
    {"AYALA", 15},
    {"GREGORY", 171},
    {"CASTANEDA", 67},
    {"HUGHES", 218},
    {"MATTHEWS", 278},
    {"BREWER", 42},
    {"PARKS", 338},
    {"HOWARD", 213},
    {"CALDWELL", 55},
    {"ROWE", 393},
    {"HIGGINS", 203},
    {"NICHOLS", 320},
    {"JIMENEZ", 228},
    {"CRAWFORD", 92},
    {"ADKINS", 2},
    {"BYRD", 52},
    {"BLAKE", 36},
    {"GORDON", 164},
    {"MCLAUGHLIN", 287},
    {"MALDONADO", 269},
    {"GREENE", 170},
    {"MCCARTHY", 281},
    {"COLLINS", 84},
    {"BOWEN", 37},
    {"ALVARADO", 7},
    {"BENNETT", 30},
    {"SCHROEDER", 407},
    {"BOWMAN", 38},
    {"JUAREZ", 234},
    {"BALDWIN", 18},
    {"BUTLER", 51},
    {"LAMBERT", 244},
    {"EVANS", 124},
    {"CABRERA", 53},
    {"HANSEN", 185},
    {"SOLIS", 424},
    {"HAYES", 196},
    {"BOYD", 39},
    {"AGUIRRE", 4},
    {"GALLAGHER", 148},
    {"BRADY", 41},
    {"ORTIZ", 330},
    {"LYONS", 267},
    {"LEE", 251},
    {"HART", 193},
    {"WATTS", 474},
    {"CURRY", 97},
    {"BROOKS", 43},
    {"GILBERT", 157},
    {"CHANDLER", 73},
    {"JENKINS", 225},
    {"DUNN", 116},
    {"FOX", 139},
    {"BROWN", 44},
    {"CAMACHO", 56},
    {"COLE", 82},
    {"GUZMAN", 178},
    {"WHEELER", 482},
    {"CAMPBELL", 57},
    {"HERRERA", 201},
    {"FERNANDEZ", 127},
    {"TOWNSEND", 446},
    {"PATEL", 340},
    {"FISCHER", 130},
    {"FLETCHER", 134},
    {"FOSTER", 137},
    {"FOWLER", 138},
    {"LITTLE", 257},
    {"FRANCO", 141},
    {"MACK", 268},
    {"HAYNES", 197},
    {"FRANCIS", 140},
    {"FRANK", 142},
    {"WILSON", 487},
    {"REYES", 369},
    {"FRANKLIN", 143},
    {"GRANT", 166},
    {"GALLEGOS", 149},
    {"GARDNER", 151},
    {"SHELTON", 414},
    {"AVILA", 14},
    {"GARNER", 152},
    {"PORTER", 355},
    {"GARZA", 154},
    {"GEORGE", 155},
    {"MOLINA", 298},
    {"GONZALES", 160},
    {"PHILLIPS", 353},
    {"HOWELL", 214},
    {"HARDY", 187},
    {"GONZALEZ", 161},
    {"GRAHAM", 165},
    {"HUDSON", 217},
    {"ROBERTSON", 381},
    {"DOYLE", 114},
    {"LI", 255},
    {"GOODWIN", 163},
    {"YOUNG", 497},
    {"GREEN", 169},
    {"PETERS", 350},
    {"BUSH", 50},
    {"GRIFFIN", 172},
    {"GROSS", 174},
    {"VAZQUEZ", 456},
    {"GUERRA", 175},
    {"GUERRERO", 176},
    {"GUTIERREZ", 177},
    {"LONG", 260},
    {"ANDREWS", 10},
    {"HAIL", 179},
    {"HALE", 180},
    {"HAMILTON", 182},
    {"KLEIN", 242},
    {"GIBSON", 156},
    {"HANSON", 186},
    {"ROBERTS", 380},
    {"HINES", 205},
    {"HARMON", 188},
    {"CARDENAS", 60},
    {"HARPER", 189},
    {"HARRINGTON", 190},
    {"HARRIS", 191},
    {"LAWRENCE", 248},
    {"HARVEY", 194},
    {"PERSON", 349},
    {"HENDERSON", 198},
    {"GOODMAN", 162},
    {"HENRY", 199},
    {"RIVERA", 378},
    {"ARNOLD", 12},
    {"LANE", 245},
    {"THORNTON", 443},
    {"HERNANDEZ", 200},
    {"HICKS", 202},
    {"CRAIG", 91},
    {"HODGES", 206},
    {"CUMMINGS", 95},
    {"HOFFMAN", 207},
    {"MORAN", 303},
    {"HOLLAND", 208},
    {"HUNTER", 220},
    {"HOLMES", 209},
    {"REED", 365},
    {"HOLT", 210},
    {"DURAN", 117},
    {"BATES", 26},
    {"HUANG", 215},
    {"JACKSON", 222},
    {"JACOBS", 223},
    {"MANN", 271},
    {"JENNINGS", 226},
    {"CONTRERAS", 86},
    {"CARROLL", 65},
    {"JENSEN", 227},
    {"JOHNSTON", 230},
    {"WRIGHT", 494},
    {"JORDAN", 232},
    {"KELLER", 235},
    {"WILLIAMSON", 485},
    {"KELLEY", 236},
    {"SMITH", 422},
    {"BURNS", 48},
    {"KELLY", 237},
    {"KIM", 240},
    {"SAUNDERS", 404},
    {"SANCHEZ", 399},
    {"SALINAS", 398},
    {"KENNEDY", 238},
    {"ROBBINS", 379},
    {"KHAN", 239},
    {"VARGAS", 453},
    {"KING", 241},
    {"RICHARDSON", 374},
    {"KNIGHT", 243},
    {"MONTOYA", 300},
    {"LARA", 246},
    {"LARSON", 247},
    {"SANTOS", 403},
    {"FLEMING", 133},
    {"LEON", 252},
    {"LUCAS", 264},
    {"CHRISTENSEN", 78},
    {"FUENTES", 146},
    {"LEWIS", 254},
};


//just a comparator to sort ssn's
bool ssnSort(Data *A, Data *B) {
  return (A->ssn) < (B->ssn);
} 


void sortT1(list<Data*>& l) {
    size_t listSize = l.size();
    Data** arr = new Data*[listSize]; // array to hold the pointers

    // Transfer data from list to array
    copy(l.begin(), l.end(), arr);

    // Sort the array
    sort(arr, arr + listSize, [](const Data* a, const Data* b) {
        if (a->lastName != b->lastName) return a->lastName < b->lastName;
        if (a->firstName != b->firstName) return a->firstName < b->firstName;
        return a->ssn < b->ssn;
    });

    // Transfer sorted data back to the list
    copy(arr, arr + listSize, l.begin());


    delete[] arr; 
}

void sortT2(list<Data*>& l, unordered_map<string, int> LastNameMap, unordered_map<string, int> FirstNameMap) {
    int totalBuckets = 500000; // Adjust based on the distribution of data

    // Function to create a combined key for last name and first name
    auto combinedKey = [&](const string& lastName, const string& firstName) {
        int lastNameKey = LastNameMap[lastName];
        int firstNameKey = FirstNameMap[firstName];
        return (lastNameKey * 1000 + firstNameKey) % totalBuckets;  
    };

    vector<list<Data*>> buckets(totalBuckets);

    // Distribute Data objects into buckets
    for (auto& data : l) {
        int bucketIndex = combinedKey(data->lastName, data->firstName);
        buckets[bucketIndex].push_back(data);
    }

    l.clear();

    // Process each bucket
    for (auto& bucket : buckets) {
        if (bucket.size() > 1) {
            // Sort by SSN if the bucket contains more than one Data object
            bucket.sort([](const Data* a, const Data* b) { return a->ssn < b->ssn; });
        }

        // Splice the sorted bucket back into the main list
        l.splice(l.end(), bucket);
    }
}



void sortT3(list<Data*>& l) {
    if (l.empty()) return;

    
    size_t listSize = l.size();
    Data** arr = new Data*[listSize]; // array to hold the pointers

    // Transfer data from list to array
    copy(l.begin(), l.end(), arr);

    // Iterate through array for sorting
    size_t startIndex = 0;
    while (startIndex < listSize) {
        size_t endIndex = startIndex;
        while (endIndex < listSize && arr[endIndex]->firstName == arr[startIndex]->firstName) { // Find the end of the current group with the same first name(similar to previous implementation)
            ++endIndex;
        }

        
        sort(arr + startIndex, arr + endIndex, ssnSort); // Sort this group by SSN

        
        startIndex = endIndex; // Move to the next group
    }

    // Transfer sorted data back to the list
    copy(arr, arr + listSize, l.begin());

    delete[] arr;
}



void sortT4(list<Data*>& l) {
  if (l.empty()) return;

  vector<Data*> Buckets[10000]; //create static array of 10000 buckets (maybe faster than vector)
 
  for (auto& data : l) {
      int i = stoi((data->ssn)); 
      Buckets[i].push_back(data);
  }

  auto it = l.begin();
    
  for (int i = 0; i < 10000; i++) {
      sort(Buckets[i].begin(), Buckets[i].end(), ssnSort); //sorts the ssn by using the comparator ssnSort used for T3

      for (auto& data : Buckets[i]) { //rebuilds list. increments iterator to point to next position and writes sorted data objects from each bucket.
          *it = data;
          ++it;
        }
    }
}



string head;
string tail;



void sortDataList(list<Data *> &l) {
size_t listSize = l.size();

if (listSize < 120000) {
        // Added Case 1 separated it from Case 2 (hopefully faster)
        sortT1(l); 
    } else {
        string head = l.front()->lastName;
        string tail = l.back()->lastName;

        if (head == tail) {
            sortT4(l); // Modified Case 4 (maybe slightly faster)
        } else if (head[0] == 'A' && tail[0] == 'Z') {
            sortT3(l); //Unchanged
        } else {
            sortT2(l, LastNameMap, FirstNameMap); //Unchanged
        }
    }
}