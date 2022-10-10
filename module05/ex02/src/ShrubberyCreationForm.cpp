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

ShrubberyCreationForm::ShrubberyCreationForm( ) {

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
	out_file << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"
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
	out_file.close();
}

///			Private:
