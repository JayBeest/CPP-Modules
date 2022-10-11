#include "ShrubberyCreationForm.hpp"
#include <fstream>

///			Public:

///			Getters / Setters

///			Constructor / Destructor

ShrubberyCreationForm::ShrubberyCreationForm( const std::string & target )
: AForm("ShrubberyCreationForm", target, 145, 137) {

	if (AForm::_loud)
	{
  		std::cout << "[ShrubberyCreationForm] Specific constructor called" << std::endl;
	}
}

ShrubberyCreationForm::ShrubberyCreationForm( )
: AForm("<default_shrubbery_form>", "<default_target>", 1, 1) {

	if (AForm::_loud)
	{
  		std::cout << "[ShrubberyCreationForm] Default constructor called" << std::endl;
	}
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & other )
: AForm("ShrubberyCreationForm", other.getTarget(), 145, 137) {

	if (AForm::_loud)
	{
  		std::cout << "[ShrubberyCreationForm] Copy constructor called" << std::endl;
	}
	if (this != &other)
	{
	  *this = other;
	}
}

ShrubberyCreationForm::~ShrubberyCreationForm( ) {

	if (AForm::_loud)
	{
  		std::cout << "[ShrubberyCreationForm] Destructor called" << std::endl;
	}
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=( const ShrubberyCreationForm & rhs ) {

	if (AForm::_loud)
	{
  		std::cout << "[ShrubberyCreationForm] Copy assignment operator called" << std::endl;
	}
	if (this != &rhs)
	{
	}
	return *this;
}

///			Functions / Methods

void	ShrubberyCreationForm::executeConcrete( ) const {

	std::string		file_name = this->getTarget().append("_shrubbery");
	std::fstream	out_file;
	out_file.exceptions ( std::fstream::failbit | std::fstream::badbit );
	try
	{
		if (out_file.is_open())
		{
			std::cerr << out_file << " is already open, quitting.." << std::endl;
			std::exit(4); // TODO exit?!?
		}
		out_file.open(file_name.c_str(), std::fstream::out | std::fstream::trunc);
	}
	catch(std::fstream::failure & e)
	{
		std::cerr << "Exception opening " << file_name << ", write protected?" << std::endl;
		std::exit(5); // TODO exit?!!?
	}
	if (std::rand() % 2) {
		out_file
				<< "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"
				   "cccccccccc:::cccc:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"
				   "cccccccccccccccccccccccccccccccccccccccc::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::cc:::::ccccccccccc\n"
				   "ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc::::::ccccccccccccc::c::c:::c::::::::::::::::::::::::cc:::::::::::::::::::::::::::::::::cc:::::::::::ccccccccccc:cccccccccccccccccccccccc\n"
				   "ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc:::cccccccc:ccccccccccc:cc::ccc:::ccc::::::ccc:::::::::::::::cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc\n"
				   "ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc::::cccccccccccccccccccccc:cc:::::;,'.'',;;;;::::cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc\n"
				   "cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc:::::;,;;:;;;:::::ccccccccccccc:;;,,,,''......'''',;;:cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc\n"
				   "cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc:;;,,,,,,;;;;,,',,,;;:::::cc:::::::'.................'''',;;:ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc\n"
				   "cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc:,'...''',,,,,,,''',,;:;;;;;;:;;;;;;,...................','''';:cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc\n"
				   "cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc:,.........'.'',,,,;;;,;;;;,''',,,,,,,'',;;;;;,'..........',;;,,;ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc\n"
				   "ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc;'...'''''....',,,,,,,,,,;;;,'..'''',;;'..'',,,,,'...',,'''',:c::cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc\n"
				   "lllllcccccccccccccccccccccccccccccccccccccccccccccccccccccccccc:,...',;;,',..',,,''',,,,,,;,,;;,'....',,.....',,,,'',,,,,,;;,;;;;:cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc\n"
				   "llllllllllllllllllllllllllccccccccccccccccccccccccccccccccccccc:,..'....,,,,.''..',,,,,''.'''',,,...'''........'''''',,,,,;;;;;,,;:ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc\n"
				   "lllllllllllllllllllllllllllllllllllllllllllllllllllcccccccc::;,,;,,,...',,;;;;,'',''''...'.''',,'',;;,'.......'',''',,,,,,,,,;;;;,;;;;:ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc\n"
				   "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllc;,'..;:;;;;;;;;::::;,','....,,;;,;;;:;:cc:;'...'',,,,,,'..',,''''',,,;,,,,,,;:ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc\n"
				   "lllllllllllllllllllllllllllllllllllllllllllllllllllllllcc::;;'.',,,,,,,,,,;;,''...''...';;::;:ccccc::;,,',,,,'''''.......''..'''''',;,'',;;;;;;,;:ccccccccccccccccccccccccccccccccclllcccccccccccccccccc\n"
				   "llllllllllllllllllllllllllllllllllllllllllllllllllllccc:;,'''.'...''''''''''.......''.',:::::ccc:;;'.'''.''''......................','....''''',,;;,;:ccccllllllcllllllcllllllllllllllllllllllllllllllll\n"
				   "lllllllllllllllllllllllllllllllllllllllllllllllllll:;,;;;;'...........'''.........',,,:cc:;::ccc,'.........',,,'''.....'''.....................'',''',:cllllllllllllllllllllllllllllllllllllllllllllllll\n"
				   "llllllllllllllllllllllllllllllllllllllllllllllllllc;,,;,,;;''..'..''..,:;'.......'',,;:::;;,,,,,'........',,,;;'.'....,;,'',,,;,'..............'''...';cllllllllllllllllllllllllllllllllllllllllllllllll\n"
				   "oooooooooooolloolllllllllllllllllllllllllllllllllllcc;'.....',,,,,,,'';:::;;;;'..',;;:c;'...'.............',;;;,','.,;:c;;;:ccc;,,'''''.......'''....',:clllllllllllllllllllllllllllllllllllllllllllllll\n"
				   "ooooooooooooooooooooooooooooooooooooolllllllllllllll:.. .....'....',,;;;:ccc:::;;:c:;'''...','...............',:;'.';;::;;::ccc;;:;::c;'...''.'',,,,'',:llllllllllllllllllllllllllllllllllllllllllllllll\n"
				   "ooooooooooooooooooooooooooooooooooooooooooooooooolc:'................'''';:::cc::;;:,......,:;'................,'..,,,,',,,';:;',;:ccc;''',,,;;,,,;;,;:cllllllllllllllllllllllllllllllllllllllllllllllll\n"
				   "ooooooooooooooooooooooooooooooooooooooooooooooool:'.....  ..  ................''',','....'..,,,'..............''''.,;,'.',,',;,'''',;;'..',,;::;,,,,,;;;:clcccllllllllllllllllllllllllllllllllllllllllll\n"
				   "ooooooooooooooooooooooooooooooooooooooooooooooolc;'''...........................',...'..;c;.................,,,''',cc,,,,,,',;'....,;,'',,',:ccc:,'',,,,,;;;;;cllllllllllllllllolllllllloooollllllllllll\n"
				   "ooooooooooooooooooooooooooooooooooooooooooooooc;;;;,'''....  ...''.......''...'',;,'',,;cl;'..''..',,;;;,',,'',,,';c:;;,....,,'...',,,',;;:cllllc;'','.''''',,;:lllllooooooooooooooooooooooooooooooooooo\n"
				   "dddddddddddddddooooooooooooooooooooooooooooool;'.'''....... ....''.........'''''''',,:cc:;,:::cc:;;,,,,,'''''.',,,clllc:''.',;;;;;,....';cllooll:,'.....'...''',:c:;:clooooooooooooooooooooooooooooooooo\n"
				   "ddddddddddddddddddddddddddddddddddddddddoool:,.......   .......''..........';:c::;,;:cclc,:llc:;;:,...........''';looool:,',;:ccl:,,''.',;cooolc::;'...''..'''',;;,,,:looooooooooooooooooooooooooooooooo\n"
				   "ddddddddddddddddddddddddddddddddddddddddddo:.........    ......,,..'........;loolc::cl:,,;looolccc:'....''''',,,';cooolc;',;:cllc;,,',;:::clcc:ccc:;,,,,''''',;,,;:::coooooooooooooooooooooooooooooooooo\n"
				   "dddddddddddddddddddddddddddddddddddddddddddl,..'.............,;;:;'.',''',;;:ccllllllcc,.;looooooooc:,.,;;;:lll:,:coolll:;cllcc:;;;:;,,;c::cc::collcllc;;:::::;,cloooooooooooooooooooooooooooooooooooooo\n"
				   "ddddddddddddddddddddddddddddddddddddddddddddo:,''..........',::;cl:'..',,;;;;;;:c::;;;;:;,;ooooolloolc;:olcclol::c:cllol;;cc::;;:llc;,;;cccclcclooollccclooooolloooooooooooooooooooooooooooooooooooooooo\n"
				   "ddddddddddddddddddddddddddddddddddddddddddoc;'...........'','''',clc;'.';:;,';cloolooc:;;,';:cooolllcc::llccloc:lc,,;:;,.',,,,,;;:lllccloooooooooolc::cloooddodddddddddddddddddddddddddddddddddddddddddd\n"
				   "xxxxxxxxxxxxxxxxxxxxxxxddddddddddddddddddo:,,,........''''',,'...':loolloooc::ldooooolcc:;,,,:odool:;,'';:,;llcl:,'.....'''',;;;;:looddddooooodoolcccclooodddddddddddddddddddddddddddddddddddddddddddddd\n"
				   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdc,'';;,..,;;'''....''....;cccclollccc:codooooc::ol:,.'colc:,''..,l:;:::,'.......''',cc:;;;:lddddol:;,;clcclclooodddddddddddddddddddddddddddddddddddddddddddddddd\n"
				   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxd:...,:clccl:;,....';:;;,,:c:;,,;::::;;;',;,,,,;,,:c;'.':;.........:do:;''......''',,;c:,,,,;cdddddoc;,,:c:clloddddddddddddddddddddddddddddddddddddddddddddddddddd\n"
				   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdc,,coddddddool;'',:llc:::;,'',,,,;;;,''..,'.',;,,,,,'..::.';;:;'..'ldlcc;',;'.';:::;;;'';:::cllllllcc:ccclddddddddddddddddddddddddddddddddddddddddddddddddddddddd\n"
				   "kkkkxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddxxxxxxxxxxddolcc:,'''''''';:;;;;;,....',:looc'......,:clolc;.';,;ll:;,';;';lol:;,''.';:;;clllloooooddddddddxddxddddddddddddddddddddddddddddddddddddddddddddddd\n"
				   "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxxxxxxxd;.......',::cl;,cl::::;,cdxxl'.......;ool:;;,,cc;:c;;:;'.';:cc:;;;;;::;;lddddddddxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddd\n"
				   "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkd,..'.....',':ooloxdddxdc;:lll;..,,',,':c,..';:c:,;llc,..,,,;c:;:ccclodoodxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
				   "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkd:,::'...',:coddooxxkkxkdllollc:;;;,;;.,lc:ccodd:'codl,.':cclooodddxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
				   "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkd:;;;''';coddddxdoodxkkkdldxxkkxdolc:,.'cxxxxxkd:;oxxc''cdxxkxxkkxxkxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
				   "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkkkkkkkkkkkkkkkkkko;;:::coxxkkkkkkxddoooooloxkkkkkkkkxxd;.:dkkkkko;;lc;.,oxkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
				   "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkkkdlldxkkkkkOkkkkkkkOkkxddxkkkkkkkkkkkkkl,;dkkkkxc,co;.,lkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk\n"
				   "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkkkOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkOOOx;,okkkko;;ol',okkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk\n"
				   "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkc;lkOOkc,:c,;oxkkkOOkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk\n"
				   "000000000000000000000000000000000000OOOO0000000OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo:lxOOk:''.,okkOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk\n"
				   "000000000000000000000000000000000000000000000000000000000000000000000OOO000000000OOOOOOOOOOOOOOOd;,okOk:..'cxOkOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkkkkkkkkkkkkkk\n"
				   "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000k;.cdkk:.,cxOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkkxdoolccl\n"
				   "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000Oc.;lxx::okO00O00OOkkxkkkkOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOxolc:;,,,'''\n"
				   "0KKKKK0OkxxxkkkkOOkxxxxxxxxxxkO0KKKKKK000000O00KKK0K000000K00000000000000000000000000000000000000o',:odlx00000000xollloooddxkkkxdooddkO000OO00OOOOOOOOOOO0000000OOOOOOOOOOOOOOOOOOOOOOOOOOOko:::,,'.'';;\n"
				   "ddxkkOkxdc;:clodxxoooxkdodoloodOKK00kxkO00OkxxO00000Okxdxk00KKKKKKKKKKKKKKKK000000000000000000000x;;clccx0000000Odldxoloooolc:;;;;;;;cdO000000000000000000000000000000000000OOOO0OOOOOOkdolc:;;:,'.'',:;\n"
				   "ddlcccodc,,;cdddxxdodkOkkxddkO0KKKKOkkkkOkkkxxxxddxdlcccclloxkO0KKKKKKKKKKKKKKKKKKKKKKKKKKKK00000Ol;;;,,lO0OOkxxxolc::;,,,,,,,,;:ccloodO0000000000000000000000000000000000000000000000Ol,',,,,;:c:,..,;;\n"
				   "c::::,,;;,',::;;:c::ldxO0OkO000kxxdddoloxkkxdddddxxdlloc:cclldddxk0KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKk:'..,cxdl::;:::::::,'''''''',,,;cccllllodkkkO00000000000000000000000000OxxxxkOkkxkkOd:,,'',:loc,'''''\n"
				   "',,,,,,;::;;::;;::;:cldkO000K0xooollc:,;cllc:c:::ccc:ccclolclllllldxxxxO0KK0OOO0KKKKKKKKKKKKKKKKKK0l'..';;,,;;;;;:llc:'..'''''',',;;'.,,',,;;:clx000OOO000OkkkO00000000kdolccccllc:::ldo:;:;;ccc:,''....\n"
				   "''',,;;,,,;;;;;;,,,,;:::cdxkO0Okkkkkdlc:cc:;,,''',,;;:::::;;cloxdl::ccloxOkddooodxO0OO00OOkxxkO0KK0o,'.,::;:::;,'',;;,''.''..'',;,,...,'.'',;ldkxxxdoodddlc:;:lodddxxxdl:::;,;;;,,'';ll:,;:;,,''''',,'..\n"
				   ";,,','...,;;:;;;,,;;;:;,:lodxxxxxxxxoc:;::;,,,,.',,;;:cc;;;:cc::;,,;;;:loddodlc::;:llllc:::::cdOKK0l'.':c;,;;;;;,'''''','''..'';;,'..'''.'',;:clcc:;:::;,,,,,,,,,,,,,,,,'',,,''''''.';,''','.'''..',,,'.\n"
				   ";;'''...','',,,,';cl:::;:loxxdooll:,',,,;;,,,,,,,,;;;:;,,,,',,,,;;::::codolllc:;,,,;;::;,,,,;:odxxo;.';ll;;;;;;,,,,,'',,,,'',,;;;;,..''''',,',,,'',,''..''.'',,,,,,''','..'''...''..'''''',,''''',,''...\n"
				   ",,,,,...''.''',,,;cc:c:;::;:::::;:;,,,,;::,,,,,,,,,,;;,,,;;,;:;;;;;;:::cc::::;,,',,;:::;;;;;:::;;;,..'cxxc;:;,,,',,,'',,;;'',:cc:::;,'.',;;;,,;;,,,,,,'..''.',,;;;;,,;;,,,,,,,,,,,',,,,,'''''.''',,,''',\n"
				   ";;;;;;,,''','',,;;;;;:cc:;;,;;:::::;::::::;;;,,;:c:;;,;;::cccc:::;;,;::cc:;,,,,,;;;;:::;;;;;:c::;:;..'lkxc;;:;;;,,;;,,,,;:;;:cccccc:;'',;;;;;;::::;;;;;;;;,,,,,;;;;;::::;;;::;;;;;,,,,,,,'',,'',,,,''',,\n"
				   ";;::;:c::;:;,,;;::::::colcclccccccccclcc::cc:::cllcc:;:cloooolclol:::::::::;::::c:;;:;;,,,,,;:::::;..'ldo:;;:::;;::::::::ccc::;;:llc:::::::;;:cc::::::cc::::;''',;;;;:::;;;;;,,'',,;,,;;:;;::;;;;;;;''',\n"
				   ":;:cclllllcc:::clllllllcccccc:cllcccccccc::cc::::cclollllcclllcc:::cc::;;::::::::::;,'.',;:::ccccl:'.';;::cccll:;:ccccllcccclc:;:llccccccllllllcc;;::cccllc:;,;;:::;;;;;;,;;,,,''',,;:;,,;;;;;,;;:::,'''\n"
				   "cccloddolc:::cllcllllcc:::clllc:;;;,;::c:;',;;;:c:::;;;;:;,,;;;,..'',,,'',::;,;:c::;'...';::::cllo:...,;;cccclll::cc:cooc:cccc:::ccclllcclloooolc:;;;;:cloc::clolc;;;;;;;:cllc;,,,,,;;;;;;;;:::::::::;,'\n"
				   "lcccloolc::;,;:;''''....'',;:,......''',,'....';,''.....'.................,;,..','........,,,,,;::,....',,;:cccc:;:::clc:::::cc::;;::c:;;;;;;;:c:;;,,,;;::;;:::;;;;:cccc:cooooolc:;,,,,;::::clcc:,''''''\n"
				   "cc:clllclcc:::;,....',,','............',,,''',;;;;'....,,,,,''..   ..'',,,,,...,:c;''''''',;;;;;;;;,'',,;,,;:ccc::ccc:c::::;:;;;,,,,;;;;,,;:::;;;,,;,;;'',,'''',;;,,,,,;:cc::clc;,,,,,,,,;;;::,''.......\n"
				   ":c:clllllllcc::::cloccc:::::;'.';::;';:c::;,,;;;;:;,',;::::;'','...',;;;;,,;,;:::::;;:cc:::cccccc:;;:;;;:;;;::::cc:::;,,,;;::::;;,;;;,;;;,,;::;,,,,,,,,,',,,;;:::;;;;::::::;::;;,,,,,''...',,,,''... ...\n"
				   "::::cclccclc::::cclolclllcllcccc:c::::cc:;;;'.''',;::;,,;;::;,;;;,,,;::::::cccc::;;;,,;:cccc::ccc:,,,'',;,,,,;;;;;;;:;'',,;;::::::;:;;::c:,',;;,',,',;::;'',::ccccllllooc;;:;:;;;;,;;,'....',,,'.''...',\n"
				   "llllllccccccclc:;;;::clllllccclc::cccclc:;;:;,,;::cc::;;:c::;,;,,,,,;:ccllclc::cc;;;''',;;;::clccc:;;;;;;;;:cclc;;;::cc::cllcc::::;,,;:::;,,,;:;,,;;::;,''',;:ccccllclllccccc:::::cc:;,''..',;,'',;;,,,,\n"
				   "odddddollccclllcllllolllcc::clolcclllooollc::clllooooolllc:::::c::::clllccc::::cccccccccccccllc::::::::::::cllllc;;::cccllool:;;,,,;,,;cc:;:::cc::c::::;;;;;;:cc:::::::::cc::::c::ccc:;::::,',;,,:cc:;,,\n"
				   "oooooddooollllloooooolc:;,';::cccloddooooooolllllloodddooolcclllcc::::ccc:::cllllloollllllc:::,'',:cccccclllloddollolccloolc;;,,;;,,,;cc:;:ccccc:::;:::;::;;::c:,',,,;;;:cc::::ccc::;,,,,,,,,,,,,',,,'''\n"
				   "oooodddooolcccloooodoc;,'.',;::cllodddddddolc:::;:clloddddddooc::::::;cllllllllccclccllcc:::::;;:cloooloddxxxddddoodooooloollc:::ccllooc;:::;;,,,,'',,,,;,,;::;,,,;;;::::;;;;;;:cc;,,''',,',,,,''......,\n"
				   "xxxdoolloodxdddxxxxdollccccllooodddxxxxdocc::;;'';:clooloollllc::;;::coddxxdollccccccccccclllodxxxxxxxxkkkkkxxdooolcccclooddol:;:cloolc:;:c;,'.',,,,''...',:lcc:;;;;;:ccc:::cc::::::c::;:::::;,''..'..';\n"
				   "xxxxddddddxxkkxxxxxxxxxxxxkxxxxxxxxxxxxdoc:;,''',:ccllllloolccc:::cclclodxxxxxxxxddooodddddolodxxxxxxxxxxxdoollllcc:ccclllcclllooooooolllllcc:;,,;;;;;;;;;cloooooolccccc::ccllcllollc:;;,;:c:;,;::::cc:c\n"
				   "xxxxxxxkkkkkkkkkxxdxxxxkkkkkxxxxxddxxddoc::c:::ccllloooddddolccccccllccoddddxxkkkkxxkkkkxxdlloooddxxxxxxxxddodddxxddddddolc:ldxxxxxxxxdxxxdoooolllcloodoodddddddddolc;;;;;;::::ccccc::;;,,;;;,;:c:::clll\n"
				   "ddoodddxxxkkkkxxdddddxxxkkkxddddddxxxxxxdollloodddxxxxxxxxxxxdoooddddoooooodxxxxxxxxxxxxxxxxxddooddddddddddoooooddooddolc::clloododdddxdddddoooooooooooollcccccllc:,'.';:::;;;:cccccloollcc::ccccccccloo\n"
				   "xddddxxxxxxxxddolloooodddxxolllcclodxxxddolllloodddxddxxxxxxxxddxxddoollooodxxxxxxxxxxxxxxxxxxdoodddxddddxdooodddddddddollllllcloodxxxxxxddddddddddddddollc::::::;,'..';;:;;;:cccccclolcc::::c::::ccccll";
	}
	else
	{
		out_file << ",xkxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddddddddddddddddddddddddddoooooooooooooooooooooooooooooooooooooooooollllllllllllllllllllllllllllllllllcccccccccccccccccccccc:::::::::::::::::. \n"
					" .oXXXXXXXXXXXXXXXXXXXXXXXXXXXXXNNXXXXXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNXXXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNO, \n"
					"  lXXXXXXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNWWNNd. \n"
					"  lKXXXXXXXXNNNNNNNNNXXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNWNNNo. \n"
					"  lKXXXXXXXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNo  \n"
					"  lKXXXXXXXXNNNNNNNNNNNNXXXXXXXXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNo  \n"
					"  lXXXXXXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNo  \n"
					"  lXXXXXXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNo  \n"
					" .oXXXXXXXXNNNNNNNNNNNNNNNNNNNNNNNNNNXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNo  \n"
					" .oXXXXXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNo  \n"
					" .oXXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNo  \n"
					" .oXXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNd. \n"
					" .oXXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNWNNNNd. \n"
					" .oXXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNWWWNNNNd. \n"
					" .oXXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNXKXNNXNNNNNXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNWWWWWWNNNNd. \n"
					" .dXXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNKOO0OO0XK0OkOXNNNNNNNNNNNNNNNXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNWWWWWWWWWNNNd. \n"
					" .dXXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNX0kdoooodxxdllxXNXNNNNXKKXXXKXNK00XNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNWWWWWWWWNNNd. \n"
					" .dXXXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNXOdlloolcolllccdOOk0XXKOkxkOkk00OxkOKNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNWWWWWWWWWNNNd. \n"
					" .dXXXXXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNXKkocccllolccloddoldO00koldkkxddddkOKXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNWWWWWWWWWWWWNNNd. \n"
					" .dXKXXXXXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNKkoc:cllcllodddloxOkdddloddolclloxk0XNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNWWWWWWWWWWWWWNNd. \n"
					" .dXKXXXXXXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNXXK0Okdol:coddollllldxddolcclol:;::cldxOXNNNXNNNNNXKK0OKXKKKKXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNWWWWWWWWWWWWWNWd. \n"
					" .dXKXXXXXXXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNXKKXKOkkxxxxxocoolddc:lodxxxoc:::cc;;:ccllldOKNX00KXNNKkxxxkOOkxk0XNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNWWWWWWWWWWWWWWNWd. \n"
					" .dXKXXXXXXXXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNK0Okkkkkxxkxdoooooooc:cllloc;clooodoccc::;,:ccccclox0KOxddkKXKOxdxOOxdox00KXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNWWWWWWWWWWWWWWWNWd. \n"
					" .dXKXXXXXXXXXXXNNNNNNNNNXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNXkollccccclolcccccccc;cc,:ol:;:::::ccccc::;:c::ccclloxkkxdxddkkxxddOOdodkOOk0XNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNWWWWWWWWWWWWWWWNNd. \n"
					" .dKKXXXXXXXXXXXXXXXXXXXXXXXNNXNNNNNNNNNNNNNNNNNNNNNNNXXNXXX0dlcc:;:ccccccccc:::c:;c;,;::;;;::cc::cc:::cc::cccclclddoodoloddodooolllllooodkOkkOXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNWWWWWWWWWWWWWWNNd. \n"
					" .dKKXXXXXXXXXXXXXXXXXXXXXXXNNXNNNNNNNNNNNNNNNNNNNNNNNK0KKOkdolc:::clcccccc:;;::::;::,.,;;,::;:lc::;;:cc:;;;:cllllllcllooooolllllccccllccccclokKNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNWWWWWWWWWWWWWWNNd. \n"
					" .dKKXXXXXXXXXXXXXXXXXXXXXXXNNNNNNNNNNNNNNNNNNNNNNNNX0xdkkdlccc::c:ccc::ccc::;:cc::ccc;::;;::cclcc:::cc::;;;:cccclddolloollllcccccllccclccc:coxkOKXXXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNWWWWWWWWWWWWWNNNd. \n"
					" .dKKXXXXXXXXXXXXXXNNNNXXXXNNNNNNNNNNNNNNNNNNNNNNNXNXxlccllc::::ccc::::;;;::::cccc:ccc::::::::cccc:;;;,;::cc:ccccclollllccclccc::::::cc:;:lolodoodxxkk0KNNNNNNNNNNNNNNNNNNNNNNNNNNNNWWWWWWWWWWWWWWNNNd. \n"
					" .xKKXXXXXXXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNKkkkdc:::::::::;;::;;::,,;;:;;;;;;;::::::cc:ccl:;:;;;:cc;;;::ccccc:::clcccccccc;;;::c:;,;clllllllodxddk0KNNNNNNNNNNNNNNNNNNNNNNNNNNWWWWWWWWWWWWWWNNNd. \n"
					" .xKKXXXXXXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNKxcccccc::;:::::;;;:::;;,,,,',,,',,,,,;;:::;:cc::ccccccc,,cc::cccc:;::::ccc:ccc:;;;:c::::;;:cccoxoodxdoxOKNNNNNNNNNNNNNNNNNNNNNNNNNNWWWWWWWWWWWWWWNNNd. \n"
					" .xXKXXXXXXXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNX0Oxolc:::::,,:c::::;,,,,',:;;''''',,''''',,,,:ccc:::::;;cl;:kkocllllc::::::cccccc;:lcccccccc::::cdxdooolloOXNNNNNNNNNNNNNNNNNNWWWWWNWWWWWWWWWWWWWWWNNNNd. \n"
					" .xXXXXXXXXXXXXXXNNNNNNNNNNNNNNNNNNNNNNNNNNKK0xllcc:::::;,'';;::::;;,,,,;;;;'',::,'''..'',;;;;;;;;;;,;:l:;okkOOOxolc:looc::::cc::ccc::coolc::cclocccclokXNNNNNNNNNNNNNNNNWWWWWWWWWWWWWWWWWWWWWWWWNNNNd. \n"
					" .xXXXXXXXXXNNXXXXXXXXXXNNNNNNNNNNNNNNNNNX0xddlcc:::::::::;,;;;:;;;;,,,',;:;,',;;,'.''''',''',,,,,,,,,;:;;oxkOxoddddc:::;;;cc::::::cc:cllcc::ccll:cc:cok0KNNNNNNNNNNNNNNWWWWWWWWWWWWWWWWWWWWWWWWWWNNNd. \n"
					" .xXXXXXXXXXNNXXXXXXXXXXNNNNNNNNNNNNNNX0kxdlcc::::::::;;;;;,;:;;;;;,,,,;;;;;:;,,;,..''','',,',;;;;,,;;;;;coddddddddkxoll:;;::::ccc:::cccccc:::cc:;:::cloxk0KKXNNWNNNNNNNWWWWWWWWWWWWWWWWWWWWWWWNNNNNNd  \n"
					" .xXKXXXXXXXNNXXXXXXXXXXNNNNNNNNNNNNNN0dooddc::,,;;:::;;,,,,;;;;;;'';,,;,,;:;'''','.'...,;::;::;;::;;,';::cllllclod0XOdc;:c:;;:ccc::::ccc:cccllc:c::cc::ccldOXNNNWWWWWWWWWWWWWWWWWWWWWWWWWWWWNNNNNNNNo  \n"
					" .xXKXXXXXXXXXXXXXXXXXXXXNNXXNNXXXNXK0kdoldkdll:,;;,;c::;;;,'',:;'',:c;;,,,;;'..','';'..;;;;;::,,;:cc;'';::::coooloxkxl;:c:::;;:::::;::::;;;;:cccc::cc;,;:cdKNNNNNNNWWWWWWWWWWWWWWWWWWWWWWWWNNNNNNNNNo  \n"
					" .xXKXXXXXXXXXXXXXXXXXXXXNXXXXXKO0KOxxdlccllooc;;;:::::::;,',''',,,;:::cc,..''..''.',..';,''',,,;:cc::,,;;;cooxkxlcool:;;;;cl:;:c:;::;;:c::::::::::ccc;;:lookKNNNNNNWWWWWNNNNNNNWWWWWWWWWWWWWWWWNNNNNo  \n"
					" .xXKXXXXXXXXXXXXXXXXXXXXXXXXXK0Okxocccc:;;;;;;;;;col:;,,,,,,,,;;,:c:lll:;'....';:;'...,;'',,,';;::;;;;;'':ooooddl::c:;,,;c::::clc::;;:c:;:cllcc:;::::;;;:cclxKNWNNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNNNNNo  \n"
					" .xXKXXXXXXXXXXXXXXXXXXXXXXXNNXXKOkdcclc:;;;,,;;:::cl;;,'',:;,:lcclllokOo,',....,:'....,:;.'',;::::;;;;;'.,:cc:cccc:;,,,;::::cl:::,',:;;,;cclllcc;::cc:;;;;::l0NWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNNNNNo  \n"
					" .kXKXXXXXXXXXXXXXXXXXXXXXXXXXXK00Odlcooc::;;;::;;;::;,,..';;,;odllccccll:,..':;.... ..';;'';;:;;;;,,,:c;.';cccllllc:'';;;:c:cl,':lc;;;,,:c::cc::cccccccccclox0XNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNNNNNo  \n"
					" .kXXXXXXXXXXXXXXXXXXXXXNNXKXXXKOkdodolc:::;::;;;;:cc:::;,,',,',:::cdl;,',;..',;. ...,odoc,',;:;,,,:cllc:;,,;:loolcc;.';:;:;;;;';odl:;;::;;;;::::::::::cccldxddOXNNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNNNNo  \n"
					" .kXXXXXXXNNNNNNNNXXNNNNXXKOOO0X0kxocl:;;::::;;,;;;::::lddl:;:::'.;loo:..';..'..  ...,c:;;,'',,;;;;ccc:::;;,',:llcc:'..,::'',,:c:;:::;;:;,;,;;:::;;;:;;:cccllllkXNNNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNNNNo  \n"
					" .kXXXNNNNNNNNNNNNNNNNNXKxddoldkxddoc:;;::::;;,,,,,,,,;;:cc:;:loo:..;ld,.,'.';......'','.',,,,,;:;;::;,,,,,,,',cc::,..',;;,;;,;;,,;;;;;:;,''',;;;;;;;;;::::ccccxKK0O0NWWWWWWWWWWWWWWWWWWWWWWWWWWWWNNNo  \n"
					" 'OXXXNNNNNNNNNNNNNNNNNKkolc:;clcc::::;::;,;,,,'',,,,'''';::c;'.... ..'..'......,;,'''::;;,.';::;,'','',,,,,,,'';,....,,;;;::,..';:;,;;;,,;;;:;,,,;;;;;;:::::ccloxdloOXXXNNNNWWWWWWWWWWWWWWWWWWWWWNNNo  \n"
					".oKKXXXXXXNNNNNNNNNNNNNKOkoc::;:::;,;;:;;;,,,,,''',,''...,,,'.''',;:;'..       .:'','.  .'..,;lcl:,;:;:::;,;;,'.''''',;;;;;;:,',,,,,;;:::;;:::,,,'',;;;;;::::cccccccldxxkOKKKNWWWWWWWWWWWWWWWWWWWWWNNo  \n"
					" :0XXXXXXNNNNNNNNNNNNNXKOkdc;;;;;;,,,;;;,,,,'''...''...,;,,,,;;;:::;;;:c;. .   .';';c'   ..':coxkolollll:,;:;,'''',,,;::;;;:,..'''',;;:cl:::;,'''',,,,;;;;::ccolc::cccccloxO0KNWWWWWWWWWWWWWWWWWWWWNNo  \n"
					" 'kXXXNNNNNNNNNNNNNNNXOxoccc:;;;;;;,,,;;,''....,,....,:;:clc:;;;;::;;:cl;..;' ....,cl'   ..clcokxocoxolc;,:cc:,...',;:lcccl:'......',,:::cc:,'',,';c;,,,;;;:::cc:::::;;ccloxOOXWWWWWWWWWWWWWWWWWWWWNNo  \n"
					" 'OXXXNNNNNNNNNNNNNXNN0dlc:;;;;:c:,'',;,,''...'''',,,,,::::c::ccccc::::::..'..';'  ..    'loccllccldxdc;,,clol,..';',:c:;'.. ..'::,'',,,;:::;,,,;:odc;;,,,;:;;;;;::::,,:cccodxKNNNNWWWWWWWWWWWWWWWNNNl  \n"
					" 'OXXXXNNNNNNNNNNNNXK0koc;,,;;;:;;;;,,:;,,'..;llc;:c;,;clc::;:ldl:;;:cc::;.   .::;'. .   .cdlcc:clool:'..':oxo.  .....'.';,.':,,clc;,;,',,;;;,;::lll:::;;;;:;;:;;:::;,,:cc:codkkO0XWWWWWWWWWWWWWWWNWNl  \n"
					" 'OXXXXNNNNNNNNNNNXKkl:;;;;:;,;;,,;cc;;,::,,;odxc;;;oxl;;c:;;;cllc:;;:::;::.  .coo; .';,. .,;;ldxoc:,..........  .'..'cdkl.;kkl:;,;;'.'''',,,',;;,,,;:;',;;::;c:;::;;,,;::ccclloxKNWWWWWWWWWWWWWWWNWNl  \n"
					" 'OXXXXNNNNNNNNXXKOxlc:;;,,,,,,,,;:cc;,,;;,,:cclc:;;:ol::;;;;;;,,;;;;;;;;;:;. .:dkd..':lc,...'coxo'.....,,;cl;.  ,do,;ddc';looloko;....''''',',;:;,,,;;,,;;::;;,;;:::;::::::coodONWWNWWWWWWWWWWWWWNWNl  \n"
					" 'OXXXXNXXNNNXXXOxoc:;;;;:::::;;;;;;;,,,;,,,',;;;:cc:;;;:;;;,',,'',;;::::;'.. .;dxkc..,;;;,...',,....';lollodo;..,l:'cd;'coooxxdoc::,.....,:c;;:ccc;,;;,,;;::::;::;,;:cccc;;:clx0NWNWWWNWWWWWWWWWWWWNl  \n"
					" ,0XXXXXXXNXXNXKOoc::;;;,;cc:;;;:;,;,';;;;;,'..'',,,,,,,,',;,.',,',,'',:c;'....,clc:;'.''';:;;'. ..':::cc:;:lo,  :ko;'.'cdodkxl;,cdo;...;:;;c:;c:;:;'','',,,;;;;::;,,,;;:c:;;ccoO0KNNNXKXNWWWWWWWWWWNl  \n"
					".oKKXXXXXXXXXXKkdl::::::;;;::;;::cllloxxc:clodxxo;,,;:;,,'''..,;,;;;;;,'';;'..',;;:cc:,''';c:::;...',;:;:ooool,  ;l;'..;oo::lccllll:'..;;;;clc::;;::,..'',,,;,,;:::c:;;,,;:;;:::lodkOOO00XNNWWWWWWWWNl  \n"
					" ;OKKXXXXXXXKkdlcc::;:::::lollddodxddxkxc::clxO0xc:clc::cc::,',;;,,cooc::lol;'.',;;;cl;..',,;,,:;....'::lxkkx:....':do,,c,.;oxxxolc'..,c;';cc:::::,''''..'',,'.',,,:c:;,::;;;::cclllddxkxk0KNWWWWWWWNl  \n"
					" 'OXKXXXXXXXXklllccccolllcdxxxk00kkkdclolc::cclolc:clcc::c:::;,'...'cllc:ldxd:.',,'';;;,'',,,,,,'''...;lclkkxc..':oxkc....:xkxxko;. .;ll:,'',;clc'..',,,,''',,,,,,',;;,',;::;;;;:oxdlcdkk0KKNWWWWWWWNl  \n"
					" 'OKKKKXXXXXXKkdoloollolloxkdddxxooooollc:clcccccclolcc:;cdxxddol:,',,;::lokOx;.....coc;,'.',,;,..'''',:c:oxl,'.':okx;...;,,oocc;...,:c:''..':;'..',,:lllcc:;,;:;,''',;,''',';c;:lddlldO0KXXWWWWWWWWNc  \n"
					" 'OKKKKKKXXXXXX0Oxoccccllllllldxlccodddlloolcccc::::;::;;lxddxkxl::c:,'';::cooc,'...,:odl,...;l:. ....,:lo::c....,;;,.. .;c;;,''..';:;,,'''',,,',;,,,,,;;lxkdlcll;,.',;;:;,,',,':clccloddkO0XWWWWWWWNc  \n"
					" 'kKKKKKKKKKKXXKOdlllccccc;;:cxkl:codxxkkkxdoc:,,:cc::;:;:lolccc:;;:c:,,''',,,,,'...:cloo:.  .lc'.....;:clc,'.......      ..''.. .,loo:,....',,,,:c:;','',:lxxodxd:,,:c:;,;;;;;;cc:::clooodx0NWWWWWWNc  \n"
					" 'kK0KKKKKKKKKKK0kkkxolc:::;:coc:coolcoolllcc::;;:c:cc:;;;;;;cl:,.':::;;,,,'...'....cl:;::'  .,,.....,c;;;'........     .'.       ..,,,....''',;:odo::cc;'';:llx0xl:;,,,,;;::;;:okxl:;;;;:lodO0XNNWWXc  \n"
					" 'k00KKKKKKKKKKKKKK00Oxxdoc;,:c::coo::::;::cll:;::;;cc;,;;'..';:,'';;,,;::,,''''....;llc:;.   ...   .... ......  'ccll:cOK0d;.        ......'',;:ccccooll;.',;:oOOdolc;,,;:;::,;cdOklcc;;:::cokXNNNWXc  \n"
					" 'k00KKKKKKKKK00KKKK00Okddxo:;:ccccc::;;:c::::;;:c;,;:;:c;,,'..,,;c:,,,;;,,,,,,,....'cdolc.             ..'.....'lxxoxOk0NNNXk:'.';:,,;'''...',,;:::ldxoc;''',;;cllc:c::::::;;,:lokOOOOdlclclx0XNWNNX:  \n"
					" 'k000000KKKKK0OOOOkxxxdodxolcc:,,;::,,;;;;;;:::lol;,;;c:.';,,,'.:dl'.',,'';;,,,'...':lol;'.          .',:;.....,;::coxkOKXNXKOxOXKkx0Od:::...'';cc:llcodc,,::;,';loc;:dxoolc;;;cldkKKXX0kOkxk0XNNNNX:  \n"
					" 'k000000KKKKK0Oddxxdddollccolc::;,''',,,,;::;;:::::;;,;'..,,,;,.','........''''.....:dxl,'.       ..';;;:,.....',;:ccodk00KXKOOKNKOKXX0d:;,.'.';;:c:cddlc:,;:colclloxdldxxxxxxoodOXXXNNNXKKX00XNNNNX:  \n"
					" 'k0O0000000KKKOkddolclool:::c:;;,,,'''''',;;,,,,',,..,::....,;'... ....',.','....  .,okdooc.     .',:l;,,....''',,,;;:ldkkO00kOKNXKXXX0o;;clc,.'',::oOOkdoc::::cooccxkoccldookkOk0XNNNNNNXXNNNNNNNNK:  \n"
					" 'k000000000K00Oxoocclooodolc:;;,,;,,:c:;::;,',,..,'.'col;....'''..',,,;ll:lxxdc.    .lOkk0o.     .';;:;......;cc:,';::lxkOkkkk0XNNNNNKkoc:lkOd:,;;,,:ldxxdoolcldOOko::cc:cllododxkO00K00XNNNNNNNNNNK:  \n"
					" 'k0O0000000000Oxooccllloool:;;;;,;;:odoc:::;;;;;;::;,';c:'..':c:;;::;,;cc:::loo,    .ckkOXx.     .cl;..    .;doc:;',:oxxkkxxkkx0NNXK00Okkoloool;',:c:,,:coxxoldxxO0ko:,:llldkOkdxdlldk0KXNNNNNNNNNNK:  \n"
					" 'kOOO0000000000Oxolc:::::;;,,:c:::;;loddllc:ccclcc:,,..''.';::cccc:,'';ldkOOOkol'    .:dOXk.     .;:,..   .'::;,;,;;;oxkkkxkkO0KNNXKK0kkxocoll:;;,';ll::ccclc:lo:;llc:;;::;:oxdodllooOXNNNNNNNNNNNNK;  \n"
					" 'xOOOOOO00000000Odc::::;;;:::::::c:;:coooc::llooo;.,:',lc::;:ooc;:cc:cddoxOOO0KXd.     ;0Nk.            .;c:::;,;,;:,:odkkkxxk0XNXXKOkkxxdloxo:;:;,,,;:lOKklc:,''';:cl:;,,,:lodxxxdod0NXNNNNNNNNNXNK;  \n"
					" 'xOOOOOOO0OOkkkOdl::clc:cccclc::cc;:c;;::::lloooc';l;,ldllc:colccldxolxxxkkkO00XO,      cKo.           'odocclcc:;,,',lxOkkdoddxxkkOOkkOxxxolllccc:;,,,;dKKO0KOdc;,;:lol:,,cloxxxkxxkKXXXXNNNNNNXXX0;  \n"
					" 'xOOOOOOOOkddocllc::lloddlccc:::clodxl;,;;;:::c;',c;;ldxdoxololodddoclxxkOOO0KKKKk'      '.          .'cdoolcooolc:;',cloollccc::clodxkkdddoc:dxddoccl:,;ok0KKKXKOoc;',;:;,;ccloodOO0KXXXXXXXXXXXXX0;  \n"
					" 'xOkOOOOOkxdolcc::::clodl::c:::::ccccc::;:::c:;;;:::lloxxkd:clclolccloldxxkO00KKKKOc.              ..::cooolccllolcc,;lllllllodooolclodddxxol:codkkdodxdolcldxkkkkkxo:'.,;,,;;:coodkOKXXXXXXXXXXXXX0,  \n"
					" 'xkkkkOOOOOkxool:::;;:::::;;;:::::cc::::::::cc:c:;cdxodkdo:;::::;;:clllodxxk000KKKKKx,            .;clcclllddddloooo;,::cloooolokko:::looxkkdllolokOxxO0KXx:okkxdxOOkkl''',,,,:c::lx0XXXXXXXXXXXXKX0,  \n"
					" 'dkkkkkkkkkkdoll::::::;;;;;;;;,;::;:c:::::;;;;,',lkkxdkxc::::;;,;;;;:::lolodO00KKKKKK0c.         .;:colcldoodoooodxxc,:lldddddddxxooddolodxkdoololok0KKKXXKkx00Okk0KKK0d:'..',:ccclkKXXXXXXXXXXXXKXO,  \n"
					" 'dxxxxxkkkxdddolc::;;;;;;;;;;;;;;;;:::,;:;,;:;.'dOxxdoddolc::;:c:::::cloodxkO0000000KK0c         ,lcloollkkxxoodxk0Oo;lddddkOxkOkOOOOOkxkxxdoooooolldOKKKKKKKKKKKKKKKKOkd:'',;;;cloxOKXXXXXXXXXKKKXO,  \n"
					" 'dxdxxxxxxxdddocc:;,,,;::;;cc:;:::;',,..,;:ll;.:xdodolloxxocc:cl::cclodxxxxxkkO00000000:        .:llcllcoxxdolloxkxxd;;odloxxxxO00KKKKKOkdxxdddddddxO00KKKKKKKKKKKKKK0Okkd:,,;;;;:ok0KKKKKKKKKKKKKKO'  \n"
					" 'oddxxxxxxxxxdoc:;;;;:c::;;ccc::;;;::;'.',,;..';c::lloooodlcllloooddxkOOOOxxxxO0000000o.        .:ccclccldxxdoccdkxdo;,clcldxxxO0K00KKK00OO0OkxkOOO0KK0KKKKKKKKK0KKKKKK000xc::ccclodOKKKKKKKKKKKK0Kk'  \n"
					" .looddddddddddollloddooolclolc:;,;:c:;,''.''...,::lddxxolllcodlcodxkkOOOOOOOOOOOOOOO0k,         .:olllcccoxkxlclxkkxo;,:c:;clooddk0000KKK00KK0O000000000000000000000000000OkddocldkO000000000000000k'  \n"
					" .:clllllllllcccllllcc:::,,:c::;;'':;,:,...','..':lloooolc:ccccooodxkOkkkOkOOOOOOOOOOx;           ,ooollccloddooddxoll:,;;;;::::cloxOOkkxolloddk00O0000000000000000000000000O0OxxdkO0000000000000000x.  \n"
					" .;::::::::::::;;;;;,,,,;',;,,,,,'';,,,'';:,'';'.':c;;cc:;:cc::clooddddoolllocclcclc:'........  ...;cccc:;:::c:;:;;::;,,,,;;;;;;;;;:cc:,,''.''',:ldk00000000000000000000000000OOOOO00000000000OOOOO0x.  \n"
					" .;:;:::::::::c::;;,,'',:,,:::;,'.',,,;,;:;,',:,..';',ccccccccccc:;,,'''.............''..'''''''',,,,,,,,,,,,,''',,,,,,,,,,,,,,,,;,,,,;,,,,,,,,,,;::ccloooddxxxxxkkxxxxxxxkOOOOOOOOOOOOOOOOOOOOOOkkOd.  \n"
					" .;:;::::::::cccc::;;;;;;,,;;;;,.',;;::;,;,',;:,..''..;::::::;,'''''''''''''''','','''''',,'',,,,,,''''''''''''''''''''',,',,,,,,,,,,,,,,,,,,,,,,,,,,'''''''',,;;;;,,;;,,,;:clllldddxxxxkkxxxxxxxxxxo.  \n"
					" .,,,;;;;;;;;;;;;;;;;;;;;;;::;;;;;;;;;::;,,,,,''''','.',,,,,,,,,,,,,,,;,,,,,,,,,,'''',,',',,,,,,,,,,,,''''''','',,,,'',,,,',,,,,,,;;,,,,,',,,,,,,,,,,,,,,,,'',,,,,'',,',;,'.'''',,,,;:::ccccoollllloc.  \n"
					" .'''',,,,,,,,,,,,,,,;,,,,,,,,,;,,,,,;;;;;:;;;;;;,,;;'';;;;,;;;,;;,,,,,,,,,,,,,,,;;,,,,;;;;,'',,,,,,,,,,,''',,,,,,;;,,,,,,,,,,,,,,;;,,,'''',,,,,,,,'',,,,;;,,,,;,,,,,,',;,,''',,,'''''''',,;llccllcl:.  \n"
					" .'''''''',,,,,,,,,,,,,,,,,,,,,,,,,,',,,;;;;;::;;:::;''::::;;;;;;;;;;:;,;;;;,;;;;::;;::;;;;;;,,,'',,,,,,,,',,,;;,;,,,;;;;;;;,,,,,;;,,,,,,,,,,,;,,,;;,,;;,,;;,,;,;;,,,,,;;,,,,,'',,''''''''',,;;:cccl;.  \n"
					"  .......'''.'..''''',''','',,,''''''',,,;;,;;;;;;;;;'';::::::::;;;:::,,:;;;;::;;,,;;;;;;;;;;;;,,;;;:;;;;,',;;;;;;;;;::::;;,,,;;;;;;;;,;;,,;,',;;;;;;,,,,,;;,,,,,,;;,,,;,,,,,''''',,,,,',,,'''',;;:c;.  \n"
					"  .................................'',,,,;;;;;;;;;;;;,,;::::::::;:ccc:,;c:::cc:::::::::cc::::::::::::::::;',::::::::::::::;;;;:;:::::::::;;:;',;;,;;;;;;,,;;,,,,,,,;;,,,,,,,,,,'''',,,,,,,,',,,,,;;;'   \n"
					" .,;;;,,,,,,,,,,,,,,,,,,,,,'''',,','',;,,,,,,,'',;;,,;,,;;;:::c:::::c;,;::::cccc::::::::::cc::::::::::;;;;,,;;::;;:::::;;:c::;:::::::::::;:::,';:;;;;;;;,,,,,,,,,,,,'',,,,,,,,,,,;;;;,,,,,,,,,'',,,,.   \n"
					" .;::;;;;;;,,,;;;;;;;;;;::::::;;;:;;;;;:::;;;;;;;;::;;,;;;::cccccccc::::::::::::::::c:::::::::;;;;;;;;;;,,;;,,;;;;;;;:;;;;::;;;::::::::::::::;:lc:;;;;;;;,,,'',,,,,'..',;::;;,,,,,,,,'''''''''''.....   \n"
					" .,;,;;;,,,,,,,,,,,;,,,,;;;,,,,;;::;;;;::::;::::::::::;:::::::::::::::cccccccc:ccccc::::::::::::::;;;;;;;;;;;::;;;;:::::::;;;;;;;;;;;;:;;::::::::;;;;;;;;,,,;;;;;,,,,,,,,;:;,.'''''''................   \n"
					" .'''''''''.'',,,,,,,,,,,,,,,,',,,,,,,;;,,,,;;;;::;,;;;;;;;;::::;;;::::::::::cccc::::::::::::;:::::::;,;;;;;;;;;;;;;::;;;:;;;,;;;,;;;;:;;;;;,;;;,,,;;;;:::::c::::::;;;,,,,,,'.....'''................   \n"
					"  ............'''''''''''...'''''''''''''''''''',,'',,,,,,,,,,,,,,,,,;;;;;;,,,;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;:;;;;;;;;;::::;;;;;;;;;;,,,,,,;;;;;;,,,,,,::::;,'''','''''''''''..'''''''...............   \n"
					"  .......................................''..........'...''''''''''.'''.'''....'''''',,,'''''',,,,,,,,,;,,',,,,;;,;;;,,,,,,,,;;;;;;;;;,,;;::;,,,,,,;,,,;;;;;'...'''''''''''''..''''''''..............   \n"
					"  ................................................................''............'''''''''''''''.'''''''''',,'''''''',,''''''''''''''''''',:;'''',,;;;:cccc::,'...''..'''''''....''''''...............   \n"
					"  ...................................................''.......'''..''...''.''.....'''''''''''''''.....'''''''''''''''''''''''''''''.....';:;;;:::cllllc:;,'''...................''''''...............   \n"
					"  .............'''...............................''.''''''''''''''''''''''''''''''''''''''''',''''''''''''''''.''''''''..'''''''''',,;;;:cc::cclolllc:;,'..''.............'''...'''''''..............   \n"
					" .................'''...''..............'''''''''''''',,'''''''''''''',,'''''''',,'',''''''',,''''''''''''''''''''''''''..''.'''''',;;;clc:::clllccc:;'..................'''....'''''''..............   \n"
					" .................'''.....'''''''''''''''''',,,,,,'''''',''''''''.'''',,,,,,,,,,,,,,,,,,,''''''''''''''''''''''''''''''''',''..'..',;:cc::c::cloolcc:,..........'.....;;'.........'..................   \n"
					"                       .............................................................................................................',,'..'''',;;,,''...............................................   .";
	}
	out_file.close();
}

///			Private:
