/*
 *	$Id: fs_exercise.c,v 1.1 2008-09-15 13:14:20 sarcher Exp $
 *
 *	:ts=4
 *
 *	Amiga ROM file system reimplementation
 *	Copyright © 2001-2005 by Olaf Barthel
 *	All Rights Reserved
 */

/****************************************************************************/

#include <exec/interrupts.h>
#include <dos/dosextens.h>

#include <clib/alib_protos.h>

/****************************************************************************/

/* Kludge for new utility.library and dos.library header files... */
#define UTILITY_DATA_STRUCTURES_H
#define FileSystemData __FileSystemData

#define __NOLIBBASE__
#include <proto/exec.h>
#include <proto/dos.h>

/****************************************************************************/

#undef UTILITY_DATA_STRUCTURES_H
#undef FileSystemData

/****************************************************************************/

extern struct Library *SysBase;
extern struct Library *DOSBase;

/****************************************************************************/

#if defined(__amigaos4__)
extern struct ExecIFace *	IExec;
extern struct DOSIFace *	IDOS;
#endif /* __amigaos4__ */

/****************************************************************************/

#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <time.h>

/****************************************************************************/

#define D_S(type,name) \
	char a_##name[sizeof(type)+3]; \
	type *name = (type *)((LONG)(a_##name+3) & ~3)

/****************************************************************************/

#include "macros.h"
#include "debug.h"

/****************************************************************************/

void reset_random_seed(void);
long get_random_number(void);
static void reset_keywords(void);
static char *get_next_keyword(void);
struct Node *create_keyword_node(void);
void create_random_dirs(char *root, int count, struct List *dest_list);
void replace_entry_with_dir(char *root, char *name);
void replace_entry_with_file(char *root, char *name);
int read_from_file(char *root, char *name, char *buffer, int offset, int len);
void make_hard_link(char *root, char *name, char *link_name);
void change_file_date(char *root, char *name, struct DateStamp *ds);
void change_file_comment(char *root, char *name, char *comment);
void delete_file(char *root, char *name);
BPTR lock_file(char *root, char *name, long mode);
BPTR open_amigados_file(char *root, char *name, long mode);
void prompt(char *msg);
void test1(char *root);
void test2(char *root);
void test3(char *root);
void test4(char *root);
void test5(char *root);
void test6(char *root);
void test7(char *root);
void test8(char *root);
void test9(char *root);
void test10(char *root);
void test11(char *root);
void test12(char *root);
void test13(char *root);
void test14(char *root);
void test15(char *root);
void test16(char *root);
void test17(char *root);
void test18(char *root);
void test19(char *root);

/****************************************************************************/

static char * heine[] =
{
	"Im traurigen Monat November war's,\n",
	"Die Tage wurden trüber,\n",
	"Der Wind riß von den Bäumen das Laub,\n",
	"Da reist ich nach Deutschland hinüber.\n\n",
	"Und als ich an die Grenze kam,\n",
	"Da fühlt ich ein stärkeres Klopfen\n",
	"In meiner Brust, ich glaube sogar\n",
	"Die Augen begunnen zu tropfen.\n\n",
	"Und als ich die deutsche Sprache vernahm,\n",
	"Da ward mir seltsam zumute;\n",
	"Ich meinte nicht anders, als ob das Herz\n",
	"Recht angenehm verblute.\n\n",
	"Ein kleines Harfenmädchen sang.\n",
	"Sie sang mit wahrem Gefühle\n",
	"Und falscher Stimme, doch ward ich sehr\n",
	"Gerühret von ihrem Spiele.\n\n",
	"Sie sang von Liebe und Liebesgram,\n",
	"Aufopfrung und Wiederfinden\n",
	"Dort oben, in jener besseren Welt,\n",
	"Wo alle Leiden schwinden.\n\n",
	"Sie sang vom irdischen Jammertal,\n",
	"Von Freuden, die bald zerronnen,\n",
	"Vom jenseits, wo die Seele schwelgt\n",
	"Verklärt in ew'gen Wonnen.\n\n",
	"Sie sang das alte Entsagungslied,\n",
	"Das Eiapopeia vom Himmel,\n",
	"Womit man einlullt, wenn es greint,\n",
	"Das Volk, den großen Lümmel.\n\n",
	"Ich kenne die Weise, ich kenne den Text,\n",
	"Ich kenn auch die Herren Verfasser;\n",
	"Ich weiß, sie tranken heimlich Wein\n",
	"Und predigten öffentlich Wasser.\n\n",
	"Ein neues Lied, ein besseres Lied,\n",
	"O Freunde, will ich euch dichten!\n",
	"Wir wollen hier auf Erden schon\n",
	"Das Himmelreich errichten.\n\n",
	"Wir wollen auf Erden glücklich sein,\n",
	"Und wollen nicht mehr darben;\n",
	"Verschlemmen soll nicht der faule Bauch,\n",
	"Was fleißige Hände erwarben.\n\n",
	"Es wächst hienieden Brot genug\n",
	"Für alle Menschenkinder,\n",
	"Auch Rosen und Myrten, Schönheit und Lust,\n",
	"Und Zuckererbsen nicht minder.\n\n",
	"Ja, Zuckererbsen für jedermann,\n",
	"Sobald die Schoten platzen!\n",
	"Den Himmel überlassen wir\n",
	"Den Engeln und den Spatzen.\n\n",
	"Und wachsen uns Flügel nach dem Tod,\n",
	"So wollen wir euch besuchen\n",
	"Dort oben, und wir, wir essen mit euch\n",
	"Die seligsten Torten und Kuchen.\n\n",
	"Ein neues Lied, ein besseres Lied!\n",
	"Es klingt wie Flöten und Geigen!\n",
	"Das Miserere ist vorbei,\n",
	"Die Sterbeglocken schweigen.\n\n",
	"Die Jungfer Europa ist verlobt\n",
	"Mit dem schönen Geniusse\n",
	"Der Freiheit, sie liegen einander im Arm,\n",
	"Sie schwelgen im ersten Kusse.\n\n",
	"Und fehlt der Pfaffensegen dabei,\n",
	"Die Ehe wird gültig nicht minder -\n",
	"Es lebe Bräutigam und Braut,\n",
	"Und ihre zukünftigen Kinder!\n\n",
	"Ein Hochzeitkarmen ist mein Lied,\n",
	"Das bessere, das neue!\n",
	"In meiner Seele gehen auf\n",
	"Die Sterne der höchsten Weihe -\n\n",
	"Begeisterte Sterne, sie lodern wild,\n",
	"Zerfließen in Flammenbächen -\n",
	"Ich fühle mich wunderbar erstarkt,\n",
	"Ich könnte Eichen zerbrechen!\n\n",
	"Seit ich auf deutsche Erde trat,\n",
	"Durchströmen mich Zaubersäfte -\n",
	"Der Riese hat wieder die Mutter berührt,\n",
	"Und es wuchsen ihm neu die Kräfte.\n\n",
	"Während die Kleine von Himmelslust\n",
	"Getrillert und musizieret,\n",
	"Ward von den preußischen Douaniers\n",
	"Mein Koffer visitieret.\n\n",
	"Beschnüffelten alles, kramten herum\n",
	"In Hemden, Hosen, Schnupftüchern;\n",
	"Sie suchten nach Spitzen, nach Bijouterien,\n",
	"Auch nach verbotenen Büchern.\n\n",
	"Ihr Toren, die ihr im Koffer sucht!\n",
	"Hier werdet ihr nichts entdecken!\n",
	"Die Konterbande, die mit mir reist,\n",
	"Die hab ich im Kopfe stecken.\n\n",
	"Hier hab ich Spitzen, die feiner sind\n",
	"Als die von Brüssel und Mecheln,\n",
	"Und pack ich einst meine Spitzen aus,\n",
	"Sie werden euch sticheln und hecheln.\n\n",
	"Im Kopfe trage ich Bijouterien,\n",
	"Der Zukunft Krondiamanten,\n",
	"Die Tempelkleinodien des neuen Gotts,\n",
	"Des großen Unbekannten.\n\n",
	"Und viele Bücher trag ich im Kopf!\n",
	"Ich darf es euch versichern,\n",
	"Mein Kopf ist ein zwitscherndes Vogelnest\n",
	"Von konfiszierlichen Büchern.\n\n",
	"Glaubt mir, in Satans Bibliothek\n",
	"Kann es nicht schlimmere geben;\n",
	"Sie sind gefährlicher noch als die\n",
	"Von Hoffmann von Fallersleben! -\n\n",
	"Ein Passagier, der neben mir stand,\n",
	"Bemerkte, ich hätte\n",
	"Jetzt vor mir den preußischen Zollverein,\n",
	"Die große Douanenkette.\n\n",
	"»Der Zollverein« - bemerkte er -\n",
	"»Wird unser Volkstum begründen,\n",
	"Er wird das zersplitterte Vaterland\n",
	"Zu einem Ganzen verbinden.\n\n",
	"Er gibt die äußere Einheit uns,\n",
	"Die sogenannt materielle;\n",
	"Die geistige Einheit gibt uns die Zensur,\n",
	"Die wahrhaft ideelle -\n\n",
	"Sie gibt die innere Einheit uns,\n",
	"Die Einheit im Denken und Sinnen;\n",
	"Ein einiges Deutschland tut uns not,\n",
	"Einig nach außen und innen.«\n\n",
	"Zu Aachen, im alten Dome, liegt\n",
	"Carolus Magnus begraben.\n",
	"(Man muß ihn nicht verwechseln mit Karl\n",
	"Mayer, der lebt in Schwaben.)\n\n",
	"Ich möchte nicht tot und begraben sein\n",
	"Als Kaiser zu Aachen im Dome;\n",
	"Weit lieber lebt' ich als kleinster Poet\n",
	"Zu Stukkert am Neckarstrome.\n\n",
	"Zu Aachen langweilen sich auf der Straß'\n",
	"Die Hunde, sie flehn untertänig:\n",
	"»Gib uns einen Fußtritt, o Fremdling, das wird\n",
	"Vielleicht uns zerstreuen ein wenig.«\n\n",
	"Ich bin in diesem langweil'gen Nest\n",
	"Ein Stündchen herumgeschlendert.\n",
	"Sah wieder preußisches Militär,\n",
	"Hat sich nicht sehr verändert.\n\n",
	"Es sind die grauen Mäntel noch\n",
	"Mit dem hohen, roten Kragen -\n",
	"(Das Rot bedeutet Franzosenblut,\n",
	"Sang Körner in früheren Tagen.)\n\n",
	"Noch immer das hölzern pedantische Volk,\n",
	"Noch immer ein rechter Winkel\n",
	"In jeder Bewegung, und im Gesicht\n",
	"Der eingefrorene Dünkel.\n\n",
	"Sie stelzen noch immer so steif herum,\n",
	"So kerzengerade geschniegelt,\n",
	"Als hätten sie verschluckt den Stock,\n",
	"Womit man sie einst geprügelt.\n\n",
	"Ja, ganz verschwand die Fuchtel nie,\n",
	"Sie tragen sie jetzt im Innern;\n",
	"Das trauliche Du wird immer noch\n",
	"An das alte Er erinnere.\n\n",
	"Der lange Schnurrbart ist eigentlich nur\n",
	"Des Zopftums neuere Phase:\n",
	"Der Zopf, der ehmals hinten hing,\n",
	"Der hängt jetzt unter der Nase.\n\n",
	"Nicht übel gefiel mir das neue Kostüm\n",
	"Der Reuter, das muß ich loben,\n",
	"Besonders die Pickelhaube, den Helm\n",
	"Mit der stählernen Spitze nach oben.\n\n",
	"Das ist so rittertümlich und mahnt\n",
	"An der Vorzeit holde Romantik,\n",
	"An die Burgfrau Johanna von Montfaucon,\n",
	"An den Freiherrn Fouqué, Uhland, Tieck.\n\n",
	"Das mahnt an das Mittelalter so schön,\n",
	"An Edelknechte und Knappen,\n",
	"Die in dem Herzen getragen die Treu\n",
	"Und auf dem Hintern ein Wappen.\n\n",
	"Das mahnt an Kreuzzug und Turnei,\n",
	"An Minne und frommes Dienen,\n",
	"An die ungedruckte Glaubenszeit,\n",
	"Wo noch keine Zeitung erschienen.\n\n",
	"Ja, ja, der Helm gefällt mir, er zeugt\n",
	"Vom allerhöchsten Witze!\n",
	"Ein königlicher Einfall war's!\n",
	"Es fehlt nicht die Pointe, die Spitze!\n\n",
	"Nur fürcht ich, wenn ein Gewitter entsteht,\n",
	"Zieht leicht so eine Spitze\n",
	"Herab auf euer romantisches Haupt\n",
	"Des Himmels modernste Blitze! - -\n\n",
	"Zu Aachen, auf dem Posthausschild,\n",
	"Sah ich den Vogel wieder,\n",
	"Der mir so tief verhaßt! Voll Gift\n",
	"Schaute er auf mich nieder.\n\n",
	"Du häßlicher Vogel, wirst du einst\n",
	"Mir in die Hände fallen;\n",
	"So rupfe ich dir die Federn aus\n",
	"Und hacke dir ab die Krallen.\n\n",
	"Du sollst mir dann, in luft'ger Höh',\n",
	"Auf einer Stange sitzen,\n",
	"Und ich rufe zum lustigen Schießen herbei\n",
	"Die rheinischen Vogelschützen.\n\n",
	"Wer mir den Vogel herunterschießt,\n",
	"Mit Zepter und Krone belehn ich\n",
	"Den wackern Mann! Wir blasen Tusch\n",
	"Und rufen: »Es lebe der König!«\n\n",
	"Zu Köllen kam ich spätabends an,\n",
	"Da hörte ich rauschen den Rheinfluß,\n",
	"Da fächelte mich schon deutsche Luft,\n",
	"Da fühlt ich ihren Einfluß -\n\n",
	"Auf meinen Appetit. Ich aß\n",
	"Dort Eierkuchen mit Schinken,\n",
	"Und da er sehr gesalzen war,\n",
	"Mußt ich auch Rheinwein trinken.\n\n",
	"Der Rheinwein glänzt noch immer wie Gold\n",
	"Im grünen Römerglase,\n",
	"Und trinkst du etwelche Schoppen zuviel,\n",
	"So steigt er dir in die Nase.\n\n",
	"In die Nase steigt ein Prickeln so süß,\n",
	"Man kann sich vor Wonne nicht lassen!\n",
	"Es trieb mich hinaus in die dämmernde Nacht,\n",
	"In die widerhallenden Gassen.\n\n",
	"Die steinernen Häuser schauten mich an,\n",
	"Als wollten sie mir berichten\n",
	"Legenden aus altverschollener Zeit,\n",
	"Der heil'gen Stadt Köllen Geschichten.\n\n",
	"Ja, hier hat einst die Klerisei\n",
	"Ihr frommes Wesen getrieben,\n",
	"Hier haben die Dunkelmänner geherrscht,\n",
	"Die Ulrich von Hutten beschrieben.\n\n",
	"Der Cancan des Mittelalters ward hier\n",
	"Getanzt von Nonnen und Mönchen;\n",
	"Hier schrieb Hochstraaten, der Menzel von Köln,\n",
	"Die gift'gen Denunziatiönchen.\n\n",
	"Die Flamme des Scheiterhaufens hat hier\n",
	"Bücher und Menschen verschlungen;\n",
	"Die Glocken wurden geläutet dabei\n",
	"Und Kyrie eleison gesungen.\n\n",
	"Dummheit und Bosheit buhlten hier\n",
	"Gleich Hunden auf freier Gasse;\n",
	"Die Enkelbrut erkennt man noch heut\n",
	"An ihrem Glaubenshasse. -\n\n",
	"Doch siehe! dort im Mondenschein\n",
	"Den kolossalen Gesellen!\n",
	"Er ragt verteufelt schwarz empor,\n",
	"Das ist der Dom von Köllen.\n\n",
	"Er sollte des Geistes Bastille sein,\n",
	"Und die listigen Römlinge dachten:\n",
	"In diesem Riesenkerker wird\n",
	"Die deutsche Vernunft verschmachten!\n\n",
	"Da kam der Luther, und er hat\n",
	"Sein großes »Halt!« gesprochen -\n",
	"Seit jenem Tage blieb der Bau\n",
	"Des Domes unterbrochen.\n\n",
	"Er ward nicht vollendet - und das ist gut.\n",
	"Denn eben die Nichtvollendung\n",
	"Macht ihn zum Denkmal von Deutschlands Kraft\n",
	"Und protestantischer Sendung.\n\n",
	"Ihr armen Schelme vom Domverein,\n",
	"Ihr wollt mit schwachen Händen\n",
	"Fortsetzen das unterbrochene Werk,\n",
	"Und die alte Zwingburg vollenden!\n\n",
	"O törichter Wahn! Vergebens wird\n",
	"Geschüttelt der Klingelbeutel,\n",
	"Gebettelt bei Ketzern und Juden sogar;\n",
	"Ist alles fruchtlos und eitel.\n\n",
	"Vergebens wird der große Franz Liszt\n",
	"Zum Besten des Doms musizieren,\n",
	"Und ein talentvoller König wird\n",
	"Vergebens deklamieren!\n\n",
	"Er wird nicht vollendet, der Kölner Dom,\n",
	"Obgleich die Narren in Schwaben\n",
	"Zu seinem Fortbau ein ganzes Schiff\n",
	"Voll Steine gesendet haben.\n\n",
	"Er wird nicht vollendet, trotz allem Geschrei\n",
	"Der Raben und der Eulen,\n",
	"Die, altertümlich gesinnt, so gern\n",
	"In hohen Kirchtürmen weilen.\n\n",
	"Ja, kommen wird die Zeit sogar,\n",
	"Wo man, statt ihn zu vollenden,\n",
	"Die inneren Räume zu einem Stall\n",
	"Für Pferde wird verwenden.\n\n",
	"»Und wird der Dom ein Pferdestall,\n",
	"Was sollen wir dann beginnen\n",
	"Mit den Heil'gen Drei Kön'gen, die da ruhn\n",
	"Im Tabernakel da drinnen?«\n\n",
	"So höre ich fragen. Doch brauchen wir uns\n",
	"In unserer Zeit zu genieren?\n",
	"Die Heil'gen Drei Kön'ge aus Morgenland,\n",
	"Sie können woanders logieren.\n\n",
	"Folgt meinem Rat und steckt sie hinein\n",
	"In jene drei Körbe von Eisen,\n",
	"Die hoch zu Münster hängen am Turm,\n",
	"Der Sankt Lamberti geheißen.\n\n",
	"Der Schneiderkönig saß darin\n",
	"Mit seinen beiden Räten,\n",
	"Wir aber benutzen die Körbe jetzt\n",
	"Für andre Majestäten.\n\n",
	"Zur Rechten soll Herr Balthasar,\n",
	"Zur Linken Herr Melchior schweben,\n",
	"In der Mitte Herr Gaspar - Gott weiß, wie einst\n",
	"Die drei gehaust im Leben!\n\n",
	"Die Heil'ge Allianz des Morgenlands,\n",
	"Die jetzt kanonisieret,\n",
	"Sie hat vielleicht nicht immer schön\n",
	"Und fromm sich aufgeführet.\n\n",
	"Der Balthasar und der Melchior,\n",
	"Das waren vielleicht zwei Gäuche,\n",
	"Die in der Not eine Konstitution\n",
	"Versprochen ihrem Reiche,\n\n",
	"Und später nicht Wort gehalten - Es hat\n",
	"Herr Gaspar, der König der Mohren,\n",
	"Vielleicht mit schwarzem Undank sogar\n",
	"Belohnt sein Volk, die Toren!\n\n",
	"Und als ich an die Rheinbrück' kam,\n",
	"Wohl an die Hafenschanze,\n",
	"Da sah ich fließen den Vater Rhein\n",
	"Im stillen Mondenglanze.\n\n",
	"»Sei mir gegrüßt, mein Vater Rhein,\n",
	"Wie ist es dir ergangen?\n",
	"Ich habe oft an dich gedacht\n",
	"Mit Sehnsucht und Verlangen.«\n\n",
	"So sprach ich, da hört ich im Wasser tief\n",
	"Gar seltsam grämliche Töne,\n",
	"Wie Hüsteln eines alten Manns,\n",
	"Ein Brümmeln und weiches Gestöhne:\n\n",
	"»Willkommen, mein Junge, das ist mir lieb,\n",
	"Daß du mich nicht vergessen;\n",
	"Seit dreizehn Jahren sah ich dich nicht,\n",
	"Mir ging es schlecht unterdessen.\n\n",
	"Zu Biberich hab ich Steine verschluckt,\n",
	"Wahrhaftig, sie schmeckten nicht lecker!\n",
	"Doch schwerer liegen im Magen mir\n",
	"Die Verse von Niklas Becker.\n\n",
	"Er hat mich besungen, als ob ich noch\n",
	"Die reinste Jungfer wäre,\n",
	"Die sich von niemand rauben läßt\n",
	"Das Kränzlein ihrer Ehre.\n\n",
	"Wenn ich es höre, das dumme Lied,\n",
	"Dann möcht ich mir zerraufen\n",
	"Den weißen Bart, ich möchte fürwahr\n",
	"Mich in mir selbst ersaufen!\n\n",
	"Daß ich keine reine Jungfer bin,\n",
	"Die Franzosen wissen es besser,\n",
	"Sie haben mit meinem Wasser so oft\n",
	"Vermischt ihr Siegergewässer.\n\n",
	"Das dumme Lied und der dumme Kerl!\n",
	"Er hat mich schmählich blamieret,\n",
	"Gewissermaßen hat er mich auch\n",
	"Politisch kompromittieret.\n\n",
	"Denn kehren jetzt die Franzosen zurück,\n",
	"So muß ich vor ihnen erröten,\n",
	"Ich, der um ihre Rückkehr so oft\n",
	"Mit Tränen zum Himmel gebeten.\n\n",
	"Ich habe sie immer so liebgehabt,\n",
	"Die lieben kleinen Französchen -\n",
	"Singen und springen sie noch wie sonst?\n",
	"Tragen noch weiße Höschen?\n\n",
	"Ich möchte sie gerne wiedersehn,\n",
	"Doch fürcht ich die Persiflage,\n",
	"Von wegen des verwünschten Lieds,\n",
	"Von wegen der Blamage.\n\n",
	"Der Alfred de Musset, der Gassenbub',\n",
	"Der kommt an ihrer Spitze\n",
	"Vielleicht als Tambour, und trommelt mir vor\n",
	"All seine schlechten Witze.«\n\n",
	"So klagte der arme Vater Rhein,\n",
	"Konnt sich nicht zufriedengeben.\n",
	"Ich sprach zu ihm manch tröstendes Wort,\n",
	"Um ihm das Herz zu heben:\n\n",
	"»O fürchte nicht, mein Vater Rhein,\n",
	"Den spöttelnden Scherz der Franzosen;\n",
	"Sie sind die alten Franzosen nicht mehr,\n",
	"Auch tragen sie andere Hosen.\n\n",
	"Die Hosen sind rot und nicht mehr weiß,\n",
	"Sie haben auch andere Knöpfe,\n",
	"Sie singen nicht mehr, sie springen nicht mehr,\n",
	"Sie senken nachdenklich die Köpfe.\n\n",
	"Sie philosophieren und sprechen jetzt\n",
	"Von Kant, von Fichte und Hegel,\n",
	"Sie rauchen Tabak, sie trinken Bier,\n",
	"Und manche schieben auch Kegel.\n\n",
	"Sie werden Philister ganz wie wir,\n",
	"Und treiben es endlich noch ärger;\n",
	"Sie sind keine Voltairianer mehr,\n",
	"Sie werden Hengstenberger.\n\n",
	"Der Alfred de Musset, das ist wahr,\n",
	"Ist noch ein Gassenjunge;\n",
	"Doch fürchte nichts, wir fesseln ihm\n",
	"Die schändliche Spötterzunge.\n\n",
	"Und trommelt er dir einen schlechten Witz,\n",
	"So pfeifen wir ihm einen schlimmern,\n",
	"Wir pfeifen ihm vor, was ihm passiert\n",
	"Bei schönen Frauenzimmern.\n\n",
	"Gib dich zufrieden, Vater Rhein,\n",
	"Denk nicht an schlechte Lieder,\n",
	"Ein besseres Lied vernimmst du bald -\n",
	"Leb wohl, wir sehen uns wieder.«\n\n",
	"Den Paganini begleitete stets\n",
	"Ein Spiritus familiaris,\n",
	"Manchmal als Hund, manchmal in Gestalt\n",
	"Des seligen Georg Harrys.\n\n",
	"Napoleon sah einen roten Mann\n",
	"Vor jedem wicht'gen Ereignis.\n",
	"Sokrates hatte seinen Dämon,\n",
	"Das war kein Hirnerzeugnis.\n\n",
	"Ich selbst, wenn ich am Schreibtisch saß\n",
	"Des Nachts, hab ich gesehen\n",
	"Zuweilen einen vermummten Gast\n",
	"Unheimlich hinter mir stehen.\n\n",
	"Unter dem Mantel hielt er etwas\n",
	"Verborgen, das seltsam blinkte,\n",
	"Wenn es zum Vorschein kam, und ein Beil,\n",
	"Ein Richtbeil, zu sein mir dünkte.\n\n",
	"Er schien von untersetzter Statur,\n",
	"Die Augen wie zwei Sterne;\n",
	"Er störte mich im Schreiben nie,\n",
	"Blieb ruhig stehn in der Ferne.\n\n",
	"Seit Jahren hatte ich nicht gesehn\n",
	"Den sonderbaren Gesellen,\n",
	"Da fand ich ihn plötzlich wieder hier\n",
	"In der stillen Mondnacht zu Köllen.\n\n",
	"Ich schlenderte sinnend die Straßen entlang,\n",
	"Da sah ich ihn hinter mir gehen,\n",
	"Als ob er mein Schatten wäre, und stand\n",
	"Ich still, so blieb er stehen.\n\n",
	"Blieb stehen, als wartete er auf was,\n",
	"Und förderte ich die Schritte,\n",
	"Dann folgte er wieder. So kamen wir\n",
	"Bis auf des Domplatz' Mitte.\n\n",
	"Es ward mir unleidlich, ich drehte mich um\n",
	"Und sprach: »Jetzt steh mir Rede,\n",
	"Was folgst du mir auf Weg und Steg\n",
	"Hier in der nächtlichen Öde?\n\n",
	"Ich treffe dich immer in der Stund',\n",
	"Wo Weltgefühle sprießen\n",
	"In meiner Brust und durch das Hirn\n",
	"Die Geistesblitze schießen.\n\n",
	"Du siehst mich an so stier und fest -\n",
	"Steh Rede: Was verhüllst du\n",
	"Hier unter dem Mantel, das heimlich blinkt?\n",
	"Wer bist du und was willst du?«\n\n",
	"Doch jener erwiderte trockenen Tons,\n",
	"Sogar ein bißchen phlegmatisch:\n",
	"»Ich bitte dich, exerziere mich nicht,\n",
	"Und werde nur nicht emphatisch!\n\n",
	"Ich bin kein Gespenst der Vergangenheit,\n",
	"Kein grabentstiegener Strohwisch,\n",
	"Und von Rhetorik bin ich kein Freund,\n",
	"Bin auch nicht sehr philosophisch.\n\n",
	"Ich bin von praktischer Natur,\n",
	"Und immer schweigsam und ruhig.\n",
	"Doch wisse: was du ersonnen im Geist,\n",
	"Das führ ich aus, das tu ich.\n\n",
	"Und gehn auch Jahre drüber hin,\n",
	"Ich raste nicht, bis ich verwandle\n",
	"In Wirklichkeit, was du gedacht;\n",
	"Du denkst, und ich, ich handle.\n\n",
	"Du bist der Richter, der Büttel bin ich,\n",
	"Und mit dem Gehorsam des Knechtes\n",
	"Vollstreck' ich das Urteil, das du gefällt,\n",
	"Und sei es ein ungerechtes.\n\n",
	"Dem Konsul trug man ein Beil voran\n",
	"Zu Rom, in alten Tagen.\n",
	"Auch du hast deinen Liktor, doch wird\n",
	"Das Beil dir nachgetragen.\n\n",
	"Ich bin dein Liktor, und ich geh\n",
	"Beständig mit dem blanken\n",
	"Richtbeile hinter dir - ich bin\n",
	"Die Tat von deinem Gedanken.«\n\n",
	"Ich ging nach Haus und schlief, als ob\n",
	"Die Engel gewiegt mich hätten.\n",
	"Man ruht in deutschen Betten so weich,\n",
	"Denn das sind Federbetten.\n\n",
	"Wie sehnt ich mich oft nach der Süßigkeit\n",
	"Des vaterländischen Pfühles,\n",
	"Wenn ich auf harten Matratzen lag,\n",
	"In der schlaflosen Nacht des Exiles!\n\n",
	"Man schläft sehr gut und träumt auch gut\n",
	"In unseren Federbetten.\n",
	"Hier fühlt die deutsche Seele sich frei\n",
	"Von allen Erdenketten.\n\n",
	"Sie fühlt sich frei und schwingt sich empor\n",
	"Zu den höchsten Himmelsräumen.\n",
	"O deutsche Seele, wie stolz ist dein Flug\n",
	"In deinen nächtlichen Träumen!\n\n",
	"Die Götter erbleichen, wenn du nahst!\n",
	"Du hast auf deinen Wegen\n",
	"Gar manches Sternlein ausgeputzt\n",
	"Mit deinen Flügelschlägen!\n\n",
	"Franzosen und Russen gehört das Land,\n",
	"Das Meer gehört den Briten,\n",
	"Wir aber besitzen im Luftreich des Traums\n",
	"Die Herrschaft unbestritten.\n\n",
	"Hier üben wir die Hegemonie,\n",
	"Hier sind wir unzerstückelt;\n",
	"Die andern Völker haben sich\n",
	"Auf platter Erde entwickelt. - -\n\n",
	"Und als ich einschlief, da träumte mir,\n",
	"Ich schlenderte wieder im hellen\n",
	"Mondschein die hallenden Straßen entlang,\n",
	"In dem altertümlichen Köllen.\n\n",
	"Und hinter mir ging wieder einher\n",
	"Mein schwarzer, vermummter Begleiter.\n",
	"Ich war so müde, mir brachen die Knie,\n",
	"Doch immer gingen wir weiter.\n\n",
	"Wir gingen weiter. Mein Herz in der Brust\n",
	"War klaffend aufgeschnitten,\n",
	"Und aus der Herzenswunde hervor\n",
	"Die roten Tropfen glitten.\n\n",
	"Ich tauchte manchmal die Finger hinein,\n",
	"Und manchmal ist es geschehen,\n",
	"Daß ich die Haustürpfosten bestrich\n",
	"Mit dem Blut im Vorübergehen.\n\n",
	"Und jedesmal, wenn ich ein Haus\n",
	"Bezeichnet in solcher Weise,\n",
	"Ein Sterbeglöckchen erscholl fernher,\n",
	"Wehmütig wimmernd und leise.\n\n",
	"Am Himmel aber erblich der Mond,\n",
	"Er wurde immer trüber;\n",
	"Gleich schwarzen Rossen jagten an ihm\n",
	"Die wilden Wolken vorüber.\n\n",
	"Und immer ging hinter mir einher\n",
	"Mit seinem verborgenen Beile\n",
	"Die dunkle Gestalt - so wanderten wir\n",
	"Wohl eine gute Weile.\n\n",
	"Wir gehen und gehen, bis wir zuletzt\n",
	"Wieder zum Domplatz gelangen;\n",
	"Weit offen standen die Pforten dort,\n",
	"Wir sind hineingegangen.\n\n",
	"Es herrschte im ungeheuren Raum\n",
	"Nur Tod und Nacht und Schweigen;\n",
	"Es brannten Ampeln hie und da,\n",
	"Um die Dunkelheit recht zu zeigen.\n\n",
	"Ich wandelte lange den Pfeilern entlang\n",
	"Und hörte nur die Tritte\n",
	"Von meinem Begleiter, er folgte mir\n",
	"Auch hier bei jedem Schritte.\n\n",
	"Wir kamen endlich zu einem Ort,\n",
	"Wo funkelnde Kerzenhelle\n",
	"Und blitzendes Gold und Edelstein;\n",
	"Das war die Drei-Königs-Kapelle.\n\n",
	"Die Heil'gen Drei Könige jedoch,\n",
	"Die sonst so still dort lagen,\n",
	"O Wunder! sie saßen aufrecht jetzt\n",
	"Auf ihren Sarkophagen.\n\n",
	"Drei Totengerippe, phantastisch geputzt,\n",
	"Mit Kronen auf den elenden\n",
	"Vergilbten Schädeln, sie trugen auch\n",
	"Das Zepter in knöchernen Händen.\n\n",
	"Wie Hampelmänner bewegten sie\n",
	"Die längstverstorbenen Knochen;\n",
	"Die haben nach Moder und zugleich\n",
	"Nach Weihrauchduft gerochen.\n\n",
	"Der eine bewegte sogar den Mund\n",
	"Und hielt eine Rede, sehr lange;\n",
	"Er setzte mir auseinander, warum\n",
	"Er meinen Respekt verlange.\n\n",
	"Zuerst weil er ein Toter sei,\n",
	"Und zweitens weil er ein König,\n",
	"Und drittens weil er ein Heil'ger sei -\n",
	"Das alles rührte mich wenig.\n\n",
	"Ich gab ihm zur Antwort lachenden Muts:\n",
	"»Vergebens ist deine Bemühung!\n",
	"Ich sehe, daß du der Vergangenheit\n",
	"Gehörst in jeder Beziehung.\n\n",
	"Fort! fort von hier! im tiefen Grab\n",
	"Ist eure natürliche Stelle.\n",
	"Das Leben nimmt jetzt in Beschlag\n",
	"Die Schätze dieser Kapelle.\n\n",
	"Der Zukunft fröhliche Kavallerie\n",
	"Soll hier im Dome hausen,\n",
	"Und weicht ihr nicht willig, so brauch ich Gewalt\n",
	"Und laß euch mit Kolben lausen!«\n\n",
	"So sprach ich, und ich drehte mich um,\n",
	"Da sah ich furchtbar blinken\n",
	"Des stummen Begleiters furchtbares Beil -\n",
	"Und er verstand mein Winken.\n\n",
	"Er nahte sich, und mit dem Beil\n",
	"Zerschmetterte er die armen\n",
	"Skelette des Aberglaubens, er schlug\n",
	"Sie nieder ohn' Erbarmen.\n\n",
	"Es dröhnte der Hiebe Widerhall\n",
	"Aus allen Gewölben, entsetzlich! -\n",
	"Blutströme schossen aus meiner Brust,\n",
	"Und ich erwachte plötzlich.\n\n",
	"Von Köllen bis Hagen kostet die Post\n",
	"Fünf Taler sechs Groschen preußisch.\n",
	"Die Diligence war leider besetzt,\n",
	"Und ich kam in die offene Beichais'.\n\n",
	"Ein Spätherbstmorgen, feucht und grau,\n",
	"Im Schlamme keuchte der Wagen;\n",
	"Doch trotz des schlechten Wetters und Wegs\n",
	"Durchströmte mich süßes Behagen.\n\n",
	"Das ist ja meine Heimatluft!\n",
	"Die glühende Wange empfand es!\n",
	"Und dieser Landstraßenkot, er ist\n",
	"Der Dreck meines Vaterlandes!\n\n",
	"Die Pferde wedelten mit dem Schwanz\n",
	"So traulich wie alte Bekannte,\n",
	"Und ihre Mistküchlein dünkten mir schön\n",
	"Wie die Äpfel der Atalante!\n\n",
	"Wir fuhren durch Mühlheim. Die Stadt ist nett,\n",
	"Die Menschen still und fleißig.\n",
	"War dort zuletzt im Monat Mai\n",
	"Des Jahres einunddreißig.\n\n",
	"Damals stand alles im Blütenschmuck,\n",
	"Und die Sonnenlichter lachten,\n",
	"Die Vögel sangen sehnsuchtvoll,\n",
	"Und die Menschen hofften und dachten -\n\n",
	"Sie dachten: Die magere Ritterschaft\n",
	"Wird bald von hinnen reisen,\n",
	"Und der Abschiedstrunk wird ihnen kredenzt\n",
	"Aus langen Flaschen von Eisen!\n\n",
	"Und die Freiheit kommt mit Spiel und Tanz,\n",
	"Mit der Fahne, der weißblauroten;\n",
	"Vielleicht holt sie sogar aus dem Grab\n",
	"Den Bonaparte, den Toten!\n\n",
	"Ach Gott! die Ritter sind immer noch hier,\n",
	"Und manche dieser Gäuche,\n",
	"Die spindeldürre gekommen ins Land,\n",
	"Die haben jetzt dicke Bäuche.\n\n",
	"Die blassen Kanaillen, die ausgesehn\n",
	"Wie Liebe, Glauben und Hoffen,\n",
	"Sie haben seitdem in unserm Wein\n",
	"Sich tote Nasen gesoffen - - -\n\n",
	"Und die Freiheit hat sich den Fuß verrenkt,\n",
	"Kann nicht mehr springen und stürmen;\n",
	"Die Trikolore in Paris\n",
	"Schaut traurig herab von den Türmen.\n\n",
	"Der Kaiser ist auferstanden seitdem,\n",
	"Doch die englischen Würmer haben\n",
	"Aus ihm einen stillen Mann gemacht,\n",
	"Und er ließ sich wieder begraben.\n\n",
	"Hab selber sein Leichenbegängnis gesehn,\n",
	"Ich sah den goldenen Wagen\n",
	"Und die goldenen Siegesgöttinnen drauf,\n",
	"Die den goldenen Sarg getragen.\n\n",
	"Den Elysäischen Feldern entlang,\n",
	"Durch des Triumphes Bogen,\n",
	"Wohl durch den Nebel, wohl über den Schnee\n",
	"Kam langsam der Zug gezogen.\n\n",
	"Mißtönend schauerlich war die Musik.\n",
	"Die Musikanten starrten\n",
	"Vor Kälte. Wehmütig grüßten mich\n",
	"Die Adler der Standarten.\n\n",
	"Die Menschen schauten so geisterhaft\n",
	"In alter Erinnrung verloren -\n",
	"Der imperiale Märchentraum\n",
	"War wieder heraufbeschworen.\n\n",
	"Ich weinte an jenem Tag. Mir sind\n",
	"Die Tränen ins Auge gekommen,\n",
	"Als ich den verschollenen Liebesruf,\n",
	"Das »Vive l'Empereur!«, vernommen.\n\n",
	"Von Köllen war ich drei Viertel auf acht\n",
	"Des Morgens fortgereiset;\n",
	"Wir kamen nach Hagen schon gegen drei,\n",
	"Da ward zu Mittag gespeiset.\n\n",
	"Der Tisch war gedeckt. Hier fand ich ganz\n",
	"Die altgermanische Küche.\n",
	"Sei mir gegrüßt, mein Sauerkraut,\n",
	"Holdselig sind deine Gerüche!\n\n",
	"Gestovte Kastanien im grünen Kohl!\n",
	"So aß ich sie einst bei der Mutter!\n",
	"Ihr heimischen Stockfische, seid mir gegrüßt!\n",
	"Wie schwimmt ihr klug in der Butter!\n\n",
	"Jedwedem fühlenden Herzen bleibt\n",
	"Das Vaterland ewig teuer -\n",
	"Ich liebe auch recht braun geschmort\n",
	"Die Bücklinge und Eier.\n\n",
	"Wie jauchzten die Würste im spritzelnden Fett!\n",
	"Die Krammetsvögel, die frommen\n",
	"Gebratenen Englein mit Apfelmus,\n",
	"Sie zwitscherten mir: »Willkommen!«\n\n",
	"»Willkommen, Landsmann« - zwitscherten sie -,\n",
	"»Bist lange ausgeblieben,\n",
	"Hast dich mit fremdem Gevögel so lang\n",
	"In der Fremde herumgetrieben!«\n\n",
	"Es stand auf dem Tische eine Gans,\n",
	"Ein stilles, gemütliches Wesen.\n",
	"Sie hat vielleicht mich einst geliebt,\n",
	"Als wir beide noch jung gewesen.\n\n",
	"Sie blickte mich an so bedeutungsvoll,\n",
	"So innig, so treu, so wehe!\n",
	"Besaß eine schöne Seele gewiß,\n",
	"Doch war das Fleisch sehr zähe.\n\n",
	"Auch einen Schweinskopf trug man auf\n",
	"In einer zinnernen Schüssel;\n",
	"Noch immer schmückt man den Schweinen bei uns\n",
	"Mit Lorbeerblättern den Rüssel.\n\n",
	"Dicht hinter Hagen ward es Nacht,\n",
	"Und ich fühlte in den Gedärmen\n",
	"Ein seltsames Frösteln. Ich konnte mich erst\n",
	"Zu Unna, im Wirtshaus, erwärmen.\n\n",
	"Ein hübsches Mädchen fand ich dort,\n",
	"Die schenkte mir freundlich den Punsch ein;\n",
	"Wie gelbe Seide das Lockenhaar,\n",
	"Die Augen sanft wie Mondschein.\n\n",
	"Den lispelnd westfälischen Akzent\n",
	"Vernahm ich mit Wollust wieder.\n",
	"Viel süße Erinnerung dampfte der Punsch,\n",
	"Ich dachte der lieben Brüder,\n\n",
	"Der lieben Westfalen, womit ich so oft\n",
	"In Göttingen getrunken,\n",
	"Bis wir gerührt einander ans Herz\n",
	"Und unter die Tische gesunken!\n\n",
	"Ich habe sie immer so liebgehabt,\n",
	"Die lieben, guten Westfalen,\n",
	"Ein Volk, so fest, so sicher, so treu,\n",
	"Ganz ohne Gleißen und Prahlen.\n\n",
	"Wie standen sie prächtig auf der Mensur\n",
	"Mit ihren Löwenherzen!\n",
	"Es fielen so grade, so ehrlich gemeint,\n",
	"Die Quarten und die Terzen.\n\n",
	"Sie fechten gut, sie trinken gut,\n",
	"Und wenn sie die Hand dir reichen\n",
	"Zum Freundschaftsbündnis, dann weinen sie;\n",
	"Sind sentimentale Eichen.\n\n",
	"Der Himmel erhalte dich, wackres Volk,\n",
	"Er segne deine Saaten,\n",
	"Bewahre dich vor Krieg und Ruhm,\n",
	"Vor Helden und Heldentaten.\n\n",
	"Er schenke deinen Söhnen stets\n",
	"Ein sehr gelindes Examen,\n",
	"Und deine Töchter bringe er hübsch\n",
	"Unter die Haube - Amen!\n"
};

static char * carroll[] =
{
	"Twas brillig, and the slithy toves\n",
	"Did gyre and gimble in the wabe\n",
	"All mimsy were the borogoves\n",
	"And the mome raths outgrabe\n\n",
	"'Beware the Jabberwock, my son\n",
	"The jaws that bite, the claws that catch\n",
	"Beware the Jubjub bird and shun\n",
	"The frumious Bandersnatch'\n\n",
	"He took his vorpal blade in hand\n",
	"Long time the manxome foe he sought\n",
	"So rested he by the Tumtum tree\n",
	"And stood awhile in thought\n",
	"And as in uffish thought he stood\n",
	"The Jabberwock, with eyes of flame\n",
	"Came whiffling through the tulgey wood\n",
	"And burbled as it came\n\n",
	"One, two, one, two\n",
	"And through and through\n",
	"The vorpal blade went snicker snack\n",
	"He left it dead, and with its head\n",
	"He went galumphing back\n\n",
	"'And hast thou slain the Jabberwock\n",
	"Come to my arms, my beamish boy\n",
	"O frabjous day! Callooh! Callay!' \n",
	"He chortled in his joy\n\n",
	"Twas brillig, and the slithy toves\n",
	"Did gyre and gimble in the wabe\n",
	"All mimsy were the borogoves\n",
	"And the mome raths outgrabe.\n"
};

/****************************************************************************/

/* Parameters of a pseudo-random-number generator from Knuth's
 * "The Art of Computer Programming, Volume 2: Seminumerical
 *  Algorithms" (3rd edition), pp. 185-186.
 */
#define MM 2147483647	/* a Mersenne prime */
#define AA 48271		/* this does well in the spectral test */
#define QQ 44488		/* (long)(MM/AA) */
#define RR 3399			/* MM % AA; it is important that RR < QQ */

static long X;

void
reset_random_seed(void)
{
	X = 0x11052001;
}

long
get_random_number(void)
{
	X = AA * (X % QQ) - RR * (long)(X / QQ);
	if(X < 0)
		X += MM;

	return(X);
}

/****************************************************************************/

static char * keywords[] =
{
	"abbrev",
	"ABEND",
	"accumulator",
	"ACK",
	"Acme",
	"acolyte",
	"ad-hockery",
	"Ada",
	"adger",
	"admin",
	"ADVENT",
	"AFAIK",
	"AFJ",
	"AI",
	"AI-complete",
	"AIDS",
	"AIDX",
	"all-elbows",
	"alt",
	"altmode",
	"amoeba",
	"amper",
	"annoybot",
	"ANSI",
	"AOS",
	"app",
	"arena",
	"arg",
	"ARMM",
	"armor-plated",
	"asbestos",
	"ASCII",
	"atomic",
	"attoparsec",
	"autobogotiphobia",
	"automagically",
	"avatar",
	"awk",
	"B1FF",
	"backgammon",
	"background",
	"BAD",
	"bagbiter",
	"bagbiting",
	"bamf",
	"bandwidth",
	"bang",
	"banner",
	"bar",
	"barf",
	"barfmail",
	"barfulation",
	"barfulous",
	"barney",
	"baroque",
	"BASIC",
	"batch",
	"baud",
	"baz",
	"bboard",
	"BBS",
	"beam",
	"beep",
	"benchmark",
	"berklix",
	"Berzerkeley",
	"beta",
	"BFI",
	"bible",
	"BiCapitalization",
	"biff",
	"big-endian",
	"bignum",
	"bigot",
	"bit",
	"bitblt",
	"BITNET",
	"bits",
	"bixie",
	"blammo",
	"blargh",
	"blast",
	"blat",
	"bletch",
	"bletcherous",
	"blink",
	"blinkenlights",
	"blit",
	"blitter",
	"blivet",
	"BLOB",
	"block",
	"BLT",
	"blurgle",
	"BNF",
	"boa",
	"board",
	"BOF",
	"BOFH",
	"bogo-sort",
	"bogometer",
	"bogon",
	"bogosity",
	"bogotify",
	"bogus",
	"boink",
	"bomb",
	"boot",
	"bounce",
	"boustrophedon",
	"box",
	"boxen",
	"boxology",
	"bozotic",
	"BQS",
	"brain-damaged",
	"brain-dead",
	"braino",
	"break",
	"breedle",
	"brittle",
	"brochureware",
	"broken",
	"BrokenWindows",
	"broket",
	"browser",
	"BRS",
	"BSD",
	"BUAF",
	"BUAG",
	"bug",
	"bug-compatible",
	"buglix",
	"bulletproof",
	"bum",
	"bump",
	"burble",
	"busy-wait",
	"buzz",
	"BWQ",
	"byte",
	"bytesexual",
	"C++",
	"calculator",
	"can",
	"candygrammar",
	"canonical",
	"careware",
	"cascade",
	"cat",
	"catatonic",
	"CDA",
	"cdr",
	"chad",
	"chain",
	"channel",
	"chanop",
	"char",
	"charityware",
	"chawmp",
	"check",
	"chemist",
	"choad",
	"choke",
	"chomp",
	"chomper",
	"CHOP",
	"chrome",
	"chug",
	"CI$",
	"clean",
	"CLM",
	"clobber",
	"clocks",
	"clone",
	"clustergeeking",
	"COBOL",
	"codes",
	"codewalker",
	"cokebottle",
	"compact",
	"compress",
	"Compu$erve",
	"computron",
	"con",
	"condom",
	"confuser",
	"cons",
	"console",
	"content-free",
	"control-C",
	"control-O",
	"control-Q",
	"control-S",
	"cookbook",
	"cookie",
	"copper",
	"copybroke",
	"copyleft",
	"copywronged",
	"core",
	"corge",
	"cowboy",
	"cracker",
	"cracking",
	"crank",
	"CrApTeX",
	"crash",
	"cray",
	"crayola",
	"crayon",
	"creationism",
	"creep",
	"cretin",
	"cretinous",
	"crippleware",
	"crlf",
	"crock",
	"cross-post",
	"crudware",
	"cruft",
	"cruftsmanship",
	"crufty",
	"crumb",
	"crunch",
	"cryppie",
	"CTSS",
	"CTY",
	"cube",
	"cubing",
	"cuspy",
	"cybercrud",
	"cyberpunk",
	"cyberspace",
	"cycle",
	"cypherpunk",
	"daemon",
	"dahmum",
	"Datamation",
	"DAU",
	"dd",
	"DDT",
	"de-rezz",
	"dead",
	"DEADBEEF",
	"deadlock",
	"dec",
	"DEC",
	"decay",
	"DEChead",
	"deckle",
	"DED",
	"defenestration",
	"dehose",
	"delint",
	"delta",
	"demented",
	"demigod",
	"demo",
	"demon",
	"depeditate",
	"deprecated",
	"derf",
	"despew",
	"diddle",
	"die",
	"diff",
	"digit",
	"dike",
	"Dilbert",
	"ding",
	"dink",
	"dinosaur",
	"dirtball",
	"disclaimer",
	"Discordianism",
	"distribution",
	"disusered",
	"doc",
	"documentation",
	"dodgy",
	"dogcow",
	"dogpile",
	"dogwash",
	"domainist",
	"dongle",
	"dongle-disk",
	"donuts",
	"doorstop",
	"down",
	"download",
	"DP",
	"DPB",
	"DPer",
	"dragon",
	"drain",
	"DRECNET",
	"driver",
	"droid",
	"drop-ins",
	"drop-outs",
	"drugged",
	"drum",
	"dump",
	"DWIM",
	"dynner",
	"earthquake",
	"EBCDIC",
	"echo",
	"elegant",
	"elephantine",
	"elite",
	"elvish",
	"EMACS",
	"email",
	"emoticon",
	"empire",
	"engine",
	"English",
	"enhancement",
	"ENQ",
	"EOF",
	"EOL",
	"EOU",
	"epoch",
	"epsilon",
	"Eris",
	"erotics",
	"evil",
	"exa-",
	"EXCH",
	"excl",
	"EXE",
	"exec",
	"Exon",
	"factor",
	"fan",
	"FAQ",
	"FAQL",
	"faradize",
	"farkled",
	"farming",
	"fascist",
	"faulty",
	"feature",
	"featurectomy",
	"feep",
	"feeper",
	"fence",
	"FidoNet",
	"Fight-o-net",
	"filk",
	"filter",
	"fine",
	"finger",
	"finn",
	"firebottle",
	"firefighting",
	"firmy",
	"fish",
	"FITNR",
	"fix",
	"FIXME",
	"flag",
	"flaky",
	"flamage",
	"flame",
	"flamer",
	"flap",
	"flarp",
	"flat",
	"flat-ASCII",
	"flat-file",
	"flatten",
	"flavor",
	"flavorful",
	"flippy",
	"flood",
	"flowchart",
	"flush",
	"flypage",
	"flytrap",
	"FM",
	"fnord",
	"FOAF",
	"FOD",
	"followup",
	"fontology",
	"foo",
	"foobar",
	"fool",
	"Foonly",
	"footprint",
	"fora",
	"foreground",
	"forked",
	"Fortrash",
	"forum",
	"fossil",
	"fragile",
	"fred",
	"frednet",
	"freeware",
	"freeze",
	"fried",
	"frink",
	"friode",
	"fritterware",
	"frob",
	"frobnicate",
	"frobnitz",
	"frog",
	"frogging",
	"frotz",
	"frotzed",
	"frowney",
	"FRS",
	"fry",
	"FSF",
	"FTP",
	"FUBAR",
	"FUD",
	"fudge",
	"fum",
	"funky",
	"furrfu",
	"fuzzball",
	"g-file",
	"gabriel",
	"gag",
	"garply",
	"gas",
	"gaseous",
	"gawble",
	"GC",
	"GCOS",
	"GECOS",
	"gedanken",
	"geef",
	"gen",
	"generate",
	"gensym",
	"GFR",
	"gig",
	"giga-",
	"GIGO",
	"gilley",
	"gillion",
	"GIPS",
	"glark",
	"glass",
	"glassfet",
	"glitch",
	"glob",
	"glork",
	"glue",
	"gnarly",
	"GNU",
	"GNUMACS",
	"gobble",
	"Godzillagram",
	"golden",
	"gonk",
	"gonkulator",
	"gonzo",
	"gopher",
	"gorets",
	"gorp",
	"GOSMACS",
	"Gosperism",
	"gotcha",
	"GPL",
	"GPV",
	"grault",
	"great-wall",
	"grep",
	"grilf",
	"grind",
	"gripenet",
	"gritch",
	"grok",
	"gronk",
	"gronked",
	"grovel",
	"grunge",
	"gubbish",
	"guiltware",
	"gumby",
	"gun",
	"gunch",
	"gurfle",
	"guru",
	"gweep",
	"hack",
	"hacker",
	"Hackintosh",
	"hackish",
	"hackishness",
	"hackitude",
	"hair",
	"hairball",
	"hairy",
	"HAKMEM",
	"hakspek",
	"hammer",
	"hamster",
	"hand-hacking",
	"hand-roll",
	"handle",
	"handshaking",
	"handwave",
	"hang",
	"happily",
	"haque",
	"hardcoded",
	"hardwarily",
	"hardwired",
	"hat",
	"HCF",
	"heartbeat",
	"heatseeker",
	"heavyweight",
	"heisenbug",
	"hex",
	"hexadecimal",
	"hexit",
	"HHOK",
	"HHOS",
	"highly",
	"hing",
	"hirsute",
	"HLL",
	"hoarding",
	"hobbit",
	"hog",
	"hole",
	"hollised",
	"hook",
	"hop",
	"hose",
	"hosed",
	"hotlink",
	"HP-SUX",
	"huff",
	"humma",
	"hung",
	"hungus",
	"hyperspace",
	"IBM",
	"ice",
	"idempotent",
	"ill-behaved",
	"IMHO",
	"inc",
	"incantation",
	"include",
	"index",
	"infinite",
	"infinity",
	"inflate",
	"Infocom",
	"initgame",
	"INTERCAL",
	"interesting",
	"Internet",
	"interrupt",
	"IRC",
	"iron",
	"ironmonger",
	"ISP",
	"ITS",
	"IWBNI",
	"IYFEG",
	"jaggies",
	"JCL",
	"JEDR",
	"JFCL",
	"jiffy",
	"jock",
	"jolix",
	"JRST",
	"JR[LN]",
	"jupiter",
	"K&R",
	"k-",
	"kahuna",
	"ken",
	"kgbvax",
	"KIBO",
	"kiboze",
	"kibozo",
	"kick",
	"kilo-",
	"KIPS",
	"kit",
	"klone",
	"kludge",
	"kluge",
	"Knuth",
	"kremvax",
	"kyrka",
	"lamer",
	"lase",
	"Lasherism",
	"laundromat",
	"LDB",
	"leak",
	"leech",
	"legal",
	"legalese",
	"LER",
	"LERP",
	"letterbomb",
	"lexer",
	"lexiphage",
	"life",
	"lightweight",
	"linearithmic",
	"link-dead",
	"lint",
	"Linux",
	"LISP",
	"list-bomb",
	"little-endian",
	"live",
	"livelock",
	"liveware",
	"lobotomy",
	"logical",
	"lose",
	"loser",
	"losing",
	"loss",
	"lossage",
	"low-bandwidth",
	"LPT",
	"lurker",
	"luser",
	"macdink",
	"machinable",
	"machoflops",
	"Macintoy",
	"Macintrash",
	"macro",
	"macro-",
	"macrology",
	"macrotape",
	"maggotbox",
	"magic",
	"mailbomb",
	"mainframe",
	"management",
	"mandelbug",
	"manged",
	"mangle",
	"mangler",
	"manularity",
	"marbles",
	"marginal",
	"marginally",
	"marketroid",
	"Mars",
	"martian",
	"massage",
	"math-out",
	"Matrix",
	"meatware",
	"meeces",
	"meg",
	"mega-",
	"megapenny",
	"MEGO",
	"meme",
	"memetics",
	"menuitis",
	"mess-dos",
	"meta",
	"MFTL",
	"mickey",
	"micro-",
	"MicroDroid",
	"microfloppies",
	"microfortnight",
	"microLenat",
	"microReid",
	"microtape",
	"middle-endian",
	"milliLampson",
	"minifloppies",
	"MIPS",
	"misbug",
	"misfeature",
	"Missed'em-five",
	"miswart",
	"moby",
	"mockingbird",
	"mod",
	"mode",
	"modulo",
	"molly-guard",
	"monstrosity",
	"monty",
	"Moof",
	"moria",
	"MOTAS",
	"MOTOS",
	"MOTSS",
	"mouso",
	"MS-DOS",
	"mu",
	"MUD",
	"muddie",
	"mudhead",
	"multician",
	"Multics",
	"multitask",
	"mumblage",
	"mumble",
	"munch",
	"munching",
	"munchkin",
	"mundane",
	"mung",
	"munge",
	"music",
	"mutter",
	"nadger",
	"nagware",
	"naive",
	"NAK",
	"nano",
	"nano-",
	"nanoacre",
	"nanobot",
	"nanocomputer",
	"nanofortnight",
	"nanotechnology",
	"nastygram",
	"nature",
	"neep-neep",
	"neophilia",
	"nerd",
	"net.-",
	"net.god",
	"net.personality",
	"net.police",
	"NetBOLLIX",
	"netburp",
	"netdead",
	"nethack",
	"netiquette",
	"netlag",
	"netnews",
	"netrock",
	"netsplit",
	"netter",
	"newbie",
	"newline",
	"news",
	"NeWS",
	"newsfroup",
	"newsgroup",
	"nick",
	"nickle",
	"NIL",
	"NMI",
	"no-op",
	"noddy",
	"node",
	"nonlinear",
	"nontrivial",
	"notwork",
	"NP-",
	"nroff",
	"NSP",
	"nude",
	"nuke",
	"number-crunching",
	"numbers",
	"nybble",
	"nyetwork",
	"Ob-",
	"Objectionable-C",
	"obscure",
	"offline",
	"ogg",
	"ooblick",
	"op",
	"open",
	"optimism",
	"orphan",
	"orthogonal",
	"OS",
	"OSU",
	"OTOH",
	"out-of-band",
	"overrun",
	"P-mail",
	"P.O.D.",
	"paper-net",
	"param",
	"PARC",
	"parm",
	"parse",
	"Pascal",
	"pastie",
	"patch",
	"path",
	"pathological",
	"payware",
	"PBD",
	"PC-ism",
	"PD",
	"PDL",
	"pdl",
	"PDP-10",
	"PDP-20",
	"peek",
	"peon",
	"percent-S",
	"perf",
	"Perl",
	"pessimal",
	"peta-",
	"PETSCII",
	"phage",
	"phase",
	"phase-wrapping",
	"phreaker",
	"phreaking",
	"pico-",
	"ping",
	"PIP",
	"pistol",
	"plain-ASCII",
	"platinum-iridium",
	"playpen",
	"playte",
	"plingnet",
	"plokta",
	"plonk",
	"plugh",
	"plumbing",
	"PM",
	"pnambic",
	"pod",
	"poke",
	"poll",
	"POM",
	"pop",
	"POPJ",
	"poser",
	"post",
	"postcardware",
	"posting",
	"postmaster",
	"PostScript",
	"PPN",
	"prepend",
	"prestidigitization",
	"prettyprint",
	"priesthood",
	"profile",
	"progasm",
	"proglet",
	"program",
	"programming",
	"proprietary",
	"protocol",
	"prowler",
	"pseudo",
	"pseudoprime",
	"pseudosuit",
	"psychedelicware",
	"psyton",
	"puff",
	"punt",
	"push",
	"quad",
	"quantifiers",
	"quarter",
	"ques",
	"quick-and-dirty",
	"quine",
	"quotient",
	"quux",
	"qux",
	"QWERTY",
	"random",
	"randomness",
	"rape",
	"rave",
	"ravs",
	"RE",
	"real",
	"reaper",
	"recursion",
	"regexp",
	"replicator",
	"reply",
	"restriction",
	"retcon",
	"RETI",
	"retrocomputing",
	"RFC",
	"RFE",
	"RL",
	"roach",
	"robot",
	"robust",
	"rococo",
	"rogue",
	"root",
	"rot13",
	"RSN",
	"RTBM",
	"RTFAQ",
	"RTFB",
	"RTFM",
	"RTFS",
	"RTI",
	"RTM",
	"RTS",
	"rude",
	"runes",
	"runic",
	"sacred",
	"saga",
	"sagan",
	"SAIL",
	"salescritter",
	"salt",
	"samizdat",
	"samurai",
	"sandbender",
	"sandbox",
	"say",
	"scag",
	"scanno",
	"schroedinbug",
	"scratch",
	"screw",
	"screwage",
	"scribble",
	"scrog",
	"scrool",
	"scrozzle",
	"scruffies",
	"SCSI",
	"ScumOS",
	"SED",
	"segfault",
	"seggie",
	"segment",
	"segv",
	"self-reference",
	"selvage",
	"semi",
	"semi-infinite",
	"server",
	"SEX",
	"sharchive",
	"shareware",
	"shelfware",
	"shell",
	"shim",
	"shitogram",
	"shovelware",
	"showstopper",
	"shriek",
	"Shub-Internet",
	"sidecar",
	"SIG",
	"silicon",
	"silo",
	"sitename",
	"skrog",
	"skulker",
	"slab",
	"slack",
	"slash",
	"sleep",
	"slim",
	"slop",
	"slopsucker",
	"slurp",
	"smart",
	"smiley",
	"smoke",
	"SMOP",
	"smurf",
	"snail",
	"snail-mail",
	"snap",
	"snarf",
	"snark",
	"sneaker",
	"sneakernet",
	"sniff",
	"snivitz",
	"SO",
	"softcopy",
	"softwarily",
	"softy",
	"SOS",
	"SPACEWAR",
	"spam",
	"special-case",
	"speedometer",
	"spell",
	"spiffy",
	"spike",
	"spin",
	"spl",
	"splat",
	"spod",
	"spoiler",
	"sponge",
	"spool",
	"squirrelcide",
	"stack",
	"state",
	"steam-powered",
	"stiffy",
	"stoppage",
	"store",
	"strided",
	"stroke",
	"strudel",
	"stubroutine",
	"studly",
	"studlycaps",
	"stunning",
	"stupid-sort",
	"Stupids",
	"suit",
	"sun-stools",
	"sunspots",
	"superloser",
	"superprogrammer",
	"superuser",
	"support",
	"surf",
	"swab",
	"swap",
	"swizzle",
	"sync",
	"sys-frog",
	"sysadmin",
	"sysape",
	"sysop",
	"system",
	"SysVile",
	"tanked",
	"TANSTAAFL",
	"taste",
	"tayste",
	"TCB",
	"TechRef",
	"TECO",
	"tee",
	"teledildonics",
	"Telerat",
	"TELNET",
	"tense",
	"tentacle",
	"tera-",
	"terminak",
	"terpri",
	"test",
	"TeX",
	"text",
	"theology",
	"theory",
	"thinko",
	"thrash",
	"thread",
	"thud",
	"thumb",
	"thunk",
	"tick",
	"times-or-divided-by",
	"TLA",
	"TMRC",
	"TMRCie",
	"toad",
	"toast",
	"toaster",
	"toeprint",
	"toggle",
	"tool",
	"toolsmith",
	"TOPS-10",
	"TOPS-20",
	"tourist",
	"touristic",
	"toy",
	"trampoline",
	"trap",
	"trash",
	"trawl",
	"tree-killer",
	"treeware",
	"trit",
	"trivial",
	"troff",
	"troglodyte",
	"troll",
	"tron",
	"true-hacker",
	"tty",
	"tube",
	"tunafish",
	"tune",
	"turist",
	"tweak",
	"tweeter",
	"TWENEX",
	"twiddle",
	"twink",
	"two-to-the-N",
	"twonkie",
	"u-",
	"UBD",
	"UN*X",
	"uninteresting",
	"Unix",
	"unixism",
	"unswizzle",
	"unwind-protect",
	"up",
	"upload",
	"upthread",
	"urchin",
	"URL",
	"Usenet",
	"user",
	"user-friendly",
	"user-obsequious",
	"UTSL",
	"UUCPNET",
	"V7",
	"vadding",
	"vanilla",
	"vannevar",
	"vaporware",
	"var",
	"VAX",
	"VAXectomy",
	"VAXen",
	"vaxherd",
	"vaxism",
	"vaxocentrism",
	"vdiff",
	"veeblefester",
	"verbage",
	"verbiage",
	"vgrep",
	"vi",
	"videotex",
	"virgin",
	"virtual",
	"virus",
	"visionary",
	"VMS",
	"voice",
	"voice-net",
	"VR",
	"wabbit",
	"WAITS",
	"waldo",
	"walk",
	"wall",
	"wallpaper",
	"wango",
	"wank",
	"wannabee",
	"warez",
	"warlording",
	"wart",
	"weasel",
	"webmaster",
	"wedged",
	"wedgie",
	"wedgitude",
	"weeble",
	"weeds",
	"weenie",
	"Weenix",
	"well-behaved",
	"well-connected",
	"wetware",
	"whack",
	"whacker",
	"whales",
	"whalesong",
	"wheel",
	"whizzy",
	"wibble",
	"WIBNI",
	"widget",
	"wiggles",
	"win",
	"Winchester",
	"windoid",
	"Windoze",
	"winkey",
	"winnage",
	"winner",
	"winnitude",
	"wired",
	"wirehead",
	"wirewater",
	"wizard",
	"wizardly",
	"wok-on-the-wall",
	"WOMBAT",
	"wonky",
	"woofer",
	"workaround",
	"worm",
	"wormhole",
	"wumpus",
	"WYSIAYG",
	"WYSIWYG",
	"XOFF",
	"XON",
	"xor",
	"xref",
	"XXX",
	"xyzzy",
	"YA-",
	"YABA",
	"YAFIYGI",
	"YAUN",
	"YKYBHTLW",
	"YMMV",
	"Yow!",
	"zap",
	"zapped",
	"zen",
	"zero",
	"zero-content",
	"zeroth",
	"zigamorph",
	"zip",
	"zipperhead",
	"zombie",
	"zorch",
	"Zork",
	"zorkmid"
};

static char keyword_taken[NUM_ENTRIES(keywords)];
static int num_keywords_left = NUM_ENTRIES(keywords);

static void
reset_keywords(void)
{
	memset(keyword_taken,0,sizeof(keyword_taken));
	num_keywords_left = NUM_ENTRIES(keywords);
}

static char *
get_next_keyword(void)
{
	char * result = NULL;

	if(num_keywords_left > 0)
	{
		int i;

		do
		{
			i = get_random_number() % NUM_ENTRIES(keywords);
		}
		while(keyword_taken[i]);

		result = keywords[i];
		keyword_taken[i] = 1;

		num_keywords_left--;
	}

	return(result);
}

/****************************************************************************/

struct Node *
create_keyword_node(void)
{
	struct Node * result = NULL;
	struct Node * n;
	char * keyword;

	keyword = get_next_keyword();
	if(keyword != NULL)
	{
		n = malloc(sizeof(*n));
		if(n != NULL)
		{
			memset(n,0,sizeof(*n));
			n->ln_Name = keyword;

			result = n;
		}
	}

	return(result);
}

/****************************************************************************/

void
create_random_dirs(char *root,int count,struct List * dest_list)
{
	char full_name[512];
	struct Node * n;
	int i;

	for(i = 0 ; i < count ; i++)
	{
		n = create_keyword_node();
		if(n != NULL)
		{
			strcpy(full_name,root);
			if(AddPart(full_name,n->ln_Name,sizeof(full_name)))
			{
				BPTR lock;

				lock = CreateDir(full_name);
				if(lock != ZERO)
				{
					AddTail(dest_list,n);
					UnLock(lock);
				}
			}
		}
	}
}

/****************************************************************************/

void
replace_entry_with_dir(char *root,char *name)
{
	char full_name[512];

	strcpy(full_name,root);
	if(AddPart(full_name,name,sizeof(full_name)))
	{
		BPTR lock;

		lock = CreateDir(full_name);
		if(lock != ZERO)
			UnLock(lock);
	}
}

/****************************************************************************/

void
replace_entry_with_file(char *root,char *name)
{
	char full_name[512];

	strcpy(full_name,root);
	if(AddPart(full_name,name,sizeof(full_name)))
	{
		BPTR file;

		file = Open(full_name,MODE_NEWFILE);
		if(file != ZERO)
		{
			Write(file,full_name,strlen(full_name));

			Close(file);
		}
	}
}

/****************************************************************************/

int
read_from_file(char *root,char *name,char *buffer,int offset,int len)
{
	char full_name[512];
	int result = -1;

	strcpy(full_name,root);
	if(AddPart(full_name,name,sizeof(full_name)))
	{
		BPTR file;

		file = Open(full_name,MODE_OLDFILE);
		if(file != ZERO)
		{
			if(offset == 0 || Seek(file,offset,OFFSET_BEGINNING) != -1)
				result = Read(file,buffer,len);

			Close(file);
		}
	}

	return(result);
}

/****************************************************************************/

void
make_hard_link(char *root,char *name,char *link_name)
{
	char full_name[512];

	strcpy(full_name,root);
	if(AddPart(full_name,name,sizeof(full_name)))
	{
		char full_link_name[512];

		strcpy(full_link_name,root);
		if(AddPart(full_link_name,link_name,sizeof(full_link_name)))
		{
			BPTR lock;

			lock = Lock(full_name,SHARED_LOCK);
			if(lock != ZERO)
			{
				MakeLink(full_link_name,lock,DOSFALSE);
				UnLock(lock);
			}
		}
	}
}

/****************************************************************************/

void
change_file_date(char *root,char *name,struct DateStamp * ds)
{
	char full_name[512];

	strcpy(full_name,root);
	if(AddPart(full_name,name,sizeof(full_name)))
	{
		struct DateStamp stamp;

		if(ds == NULL)
		{
			DateStamp(&stamp);
			ds = &stamp;
		}

		SetFileDate(full_name,ds);
	}
}

/****************************************************************************/

void
change_file_comment(char *root,char *name,char *comment)
{
	char full_name[512];

	strcpy(full_name,root);
	if(AddPart(full_name,name,sizeof(full_name)))
	{
		if(comment == NULL)
			comment = "";

		SetComment(full_name,comment);
	}
}

/****************************************************************************/

void
delete_file(char *root,char *name)
{
	char full_name[512];

	strcpy(full_name,root);
	if(AddPart(full_name,name,sizeof(full_name)))
		DeleteFile(full_name);
}

/****************************************************************************/

BPTR
lock_file(char *root,char *name,long mode)
{
	char full_name[512];
	BPTR result = ZERO;

	strcpy(full_name,root);
	if(AddPart(full_name,name,sizeof(full_name)))
		result = Lock(full_name,mode);

	return(result);
}

/****************************************************************************/

BPTR
open_amigados_file(char *root,char *name,long mode)
{
	char full_name[512];
	BPTR result = ZERO;

	strcpy(full_name,root);
	if(AddPart(full_name,name,sizeof(full_name)))
		result = Open(full_name,mode);

	return(result);
}

/****************************************************************************/

void
prompt(char *msg)
{
	if(msg != NULL)
		printf("%s ",msg);

	printf("[Return to continue]");
	fflush(stdout);
	getchar();
}

/****************************************************************************/

void
test1(char *root)
{
	struct List dir_list;
	struct Node * n;
	int half;
	int count;

	printf("1. Create and delete directory entries.\n");

	NewList(&dir_list);

	count = (get_random_number() % 100) + 100;
	printf("Create and delete %d random directories ",count);
	prompt(NULL);

	create_random_dirs(root,count,&dir_list);

	prompt("Ready to delete directories");
	half = count / 2;

	for(n = dir_list.lh_Head ;
	    n->ln_Succ != NULL ;
	    n = n->ln_Succ)
	{
		if(half > 0 && (--half) == 0)
			prompt("Half of the directories deleted");

		delete_file(root,n->ln_Name);
	}
}

/****************************************************************************/

void
test2(char *root)
{
	printf("2. Create and replace files and directories.\n");

	prompt("Ready to begin");

	replace_entry_with_file(root,"file");
	replace_entry_with_dir(root,"dir");

	prompt("Replace directory with file");
	replace_entry_with_file(root,"dir");

	prompt("Replace file with file");
	replace_entry_with_file(root,"file");

	prompt("Replace file with directory");
	replace_entry_with_dir(root,"file");

	prompt("Replace directory with directory");
	replace_entry_with_dir(root,"dir");

	delete_file(root,"file");
	delete_file(root,"dir");
}

/****************************************************************************/

void
test3(char *root)
{
	printf("3. Create and delete hard links.\n");

	prompt("Ready to begin");

	replace_entry_with_file(root,"file");
	replace_entry_with_dir(root,"dir");

	prompt("Create link to file");
	make_hard_link(root,"file","hard_link_to_file");

	prompt("Create link to directory");
	make_hard_link(root,"dir","hard_link_to_dir");

	prompt("Create link to linked file");
	make_hard_link(root,"hard_link_to_file","hard_link2_to_file");

	prompt("Create link to root directory");
	make_hard_link(root,"","hard_link_to_root");

	prompt("Delete hard links to file, then the file");
	delete_file(root,"hard_link2_to_file");
	delete_file(root,"hard_link_to_file");
	delete_file(root,"file");

	prompt("Delete directory and links to it");
	delete_file(root,"dir");
	delete_file(root,"hard_link_to_dir");
}

/****************************************************************************/

void
test4(char *root)
{
	struct List dir_list;
	struct DateStamp then;
	struct Node * n;
	int count;

	NewList(&dir_list);

	count = (get_random_number() % 100) + 100;
	printf("4. Create %d random directories, change the creation time.\n",count);

	prompt("Ready to begin");

	create_random_dirs(root,count,&dir_list);

	prompt("Ready to modify directories");

	DateStamp(&then);
	then.ds_Days -= 1;

	for(n = dir_list.lh_Head ;
	    n->ln_Succ != NULL ;
	    n = n->ln_Succ)
	{
		change_file_date(root,n->ln_Name,&then);
	}

	prompt("Ready to delete directories");

	for(n = dir_list.lh_Head ;
	    n->ln_Succ != NULL ;
	    n = n->ln_Succ)
	{
		delete_file(root,n->ln_Name);
	}
}

/****************************************************************************/

void
test5(char *root)
{
	struct List dir_list;
	struct Node * n;
	char comment[80];
	int count;
	int half;
	int len;

	NewList(&dir_list);

	count = (get_random_number() % 100) + 100;
	printf("5. Create %d random directories, change comments.\n",count);

	prompt("Ready to begin");

	create_random_dirs(root,count,&dir_list);

	prompt("Ready to change comments");

	half = count / 2;

	for(n = dir_list.lh_Head ;
	    n->ln_Succ != NULL ;
	    n = n->ln_Succ)
	{
		if(half > 0 && (--half == 0))
			prompt("Half of the comments changed");

		change_file_comment(root,n->ln_Name,"##############################################################################");
	}

	prompt("Ready to change the file comments again");

	half = count / 2;

	for(n = dir_list.lh_Head ;
	    n->ln_Succ != NULL ;
	    n = n->ln_Succ)
	{
		if(half > 0 && (--half == 0))
			prompt("Half of the comments changed");

		len = (get_random_number() % 78);
		strcpy(comment,"##############################################################################");
		comment[len] = '\0';

		change_file_comment(root,n->ln_Name,comment);
	}

	prompt("Ready to delete directories");

	for(n = dir_list.lh_Head ;
	    n->ln_Succ != NULL ;
	    n = n->ln_Succ)
	{
		delete_file(root,n->ln_Name);
	}
}

/****************************************************************************/

void
test6(char *root)
{
	BPTR lock;

	printf("6. Deleting and locking files.\n");

	prompt("Trying to delete 'file_does_not_exist'");
	delete_file(root,"file_does_not_exist");

	prompt("Trying to delete 'file/does/not/exist'");
	delete_file(root,"file/does/not/exist");

	prompt("Create dir 'foo'");
	replace_entry_with_dir(root,"foo");

	prompt("Create dir 'foo/bar'");
	replace_entry_with_dir(root,"foo/bar");

	prompt("Obtain lock on 'foo/bar'");
	lock = lock_file(root,"foo/bar",SHARED_LOCK);

	prompt("Deleting 'foo/bar'");
	delete_file(root,"foo/bar");

	prompt("Unlocking 'foo/bar', then deleting 'foo/bar' and 'foo'");
	UnLock(lock);
	delete_file(root,"foo/bar");
	delete_file(root,"foo");
}

/****************************************************************************/

void
test7(char *root)
{
	struct List dir_list;
	struct Node * n;
	int count;
	int half;
	int r;

	NewList(&dir_list);

	count = (get_random_number() % 100) + 100;
	printf("7. Create %d random directories, delete in random order.\n",count);

	prompt("Ready to begin");

	create_random_dirs(root,count,&dir_list);

	prompt("Ready to delete");

	half = count / 2;

	while(count > 0)
	{
		r = get_random_number() % count;

		for(n = dir_list.lh_Head ;
		    n->ln_Succ != NULL ;
		    n = n->ln_Succ)
		{
			if(r == 0)
				break;

			r--;
		}

		if(n->ln_Succ != NULL)
		{
			delete_file(root,n->ln_Name);

			if(half > 0 && (--half == 0))
				prompt("Half of the directories deleted");

			Remove(n);
			count--;
		}
	}
}

/****************************************************************************/

void
test8(char *root)
{
	struct MsgPort * mp = DeviceProc(root);
	BPTR lock;

	printf("8. Create, lock and delete directory entries; eject and reload medium in between.\n");

	prompt("Create dir 'foo'");
	replace_entry_with_dir(root,"foo");

	prompt("Create dir 'foo/bar'");
	replace_entry_with_dir(root,"foo/bar");

	prompt("Obtain lock on 'foo/bar'");
	lock = lock_file(root,"foo/bar",SHARED_LOCK);

	prompt("Ejecting medium");
	if(mp != NULL)
		DoPkt(mp,ACTION_DEBUG_EJECT,	0,0,0,0,0);

	prompt("Deleting 'foo/bar'");
	delete_file(root,"foo/bar");

	prompt("Loading medium");
	if(mp != NULL)
		DoPkt(mp,ACTION_DEBUG_LOAD,	0,0,0,0,0);

	prompt("Unlocking 'foo/bar', then deleting 'foo/bar' and 'foo'");
	UnLock(lock);
	delete_file(root,"foo/bar");
	delete_file(root,"foo");
}

/****************************************************************************/

void
test9(char *root)
{
	struct List dir_list;
	BPTR lock;
	int count;

	NewList(&dir_list);

	count = (get_random_number() % 100) + 100;

	printf("9. Create %d random directories, scan for and delete entries.\n",count);

	prompt("Ready to begin");

	create_random_dirs(root,count,&dir_list);

	prompt("Locking root dir, starting to scan");

	lock = Lock(root,SHARED_LOCK);
	if(lock != ZERO)
	{
		BPTR old_dir_lock;
		D_S(struct FileInfoBlock,fib);

		old_dir_lock = CurrentDir(lock);

		if(Examine(lock,fib))
		{
			prompt("Scanning directory, deleting each entry found");

			while(ExNext(lock,fib))
			{
				printf("Deleting '%s'\n",fib->fib_FileName);

				DeleteFile(fib->fib_FileName);
			}
		}

		CurrentDir(old_dir_lock);
		UnLock(lock);
	}
}

/****************************************************************************/

void
test10(char *root)
{
	struct List dir_list;
	BPTR lock1;
	BPTR lock2;
	int count;

	NewList(&dir_list);

	count = (get_random_number() % 100) + 100;
	printf("10. Create %d random directories, two scanners, delete while scanning.\n",count);

	prompt("Ready to begin");

	create_random_dirs(root,count,&dir_list);

	prompt("Locking root dir, starting to scan");

	lock1 = Lock(root,SHARED_LOCK);
	if(lock1 != ZERO)
	{
		lock2 = DupLock(lock1);
		if(lock2 != ZERO)
		{
			BPTR old_dir_lock;
			D_S(struct FileInfoBlock,fib1);
			D_S(struct FileInfoBlock,fib2);

			old_dir_lock = CurrentDir(lock1);

			if(Examine(lock1,fib1) && Examine(lock2,fib2))
			{
				prompt("Scanning directory, deleting each entry found");

				while(ExNext(lock1,fib1))
				{
					printf("Deleting '%s'\n",fib1->fib_FileName);

					DeleteFile(fib1->fib_FileName);

					if(ExNext(lock2,fib2))
						printf("Next to delete is '%s'\n",fib2->fib_FileName);
				}
			}

			CurrentDir(old_dir_lock);

			UnLock(lock2);
		}

		UnLock(lock1);
	}
}

/****************************************************************************/

void
test11(char *root)
{
	struct List dir_list;
	struct Node * n;
	BPTR lock;
	int count;
	int half;
	int r;

	NewList(&dir_list);

	count = (get_random_number() % 100) + 100;
	printf("11. Create %d random directories, scan and delete random files.\n",count);

	prompt("Ready to begin");

	create_random_dirs(root,count,&dir_list);

	prompt("Locking root dir, starting to scan");

	half = count / 2;

	lock = Lock(root,SHARED_LOCK);
	if(lock != ZERO)
	{
		BPTR old_dir_lock;
		D_S(struct FileInfoBlock,fib);

		old_dir_lock = CurrentDir(lock);

		if(Examine(lock,fib))
		{
			prompt("Scanning directory, deleting each entry found");

			while(ExNext(lock,fib))
			{
				printf("Found '%s'\n",fib->fib_FileName);

				if(count > 0)
				{
					r = get_random_number() % count;

					for(n = dir_list.lh_Head ;
					    n->ln_Succ != NULL ;
					    n = n->ln_Succ)
					{
						if(r == 0)
							break;

						r--;
					}

					if(n->ln_Succ != NULL)
					{
						printf("Deleting '%s'\n",n->ln_Name);
						DeleteFile(n->ln_Name);

						if(half > 0 && (--half == 0))
							prompt("Half of the directories deleted");

						Remove(n);
						count--;
					}
				}
			}
		}

		printf("Scanning finished; now cleaning up.\n");

		for(n = dir_list.lh_Head ;
		    n->ln_Succ != NULL ;
		    n = n->ln_Succ)
		{
			printf("Deleting '%s'\n",n->ln_Name);
			DeleteFile(n->ln_Name);
		}

		CurrentDir(old_dir_lock);
		UnLock(lock);
	}
}

/****************************************************************************/

void
test12(char *root)
{
	BPTR file;

	printf("12. Create file, store data, overwrite file.\n");

	prompt("Creating empty file 'empty_file' with MODE_NEWFILE");

	file = open_amigados_file(root,"empty_file",MODE_NEWFILE);
	if(file != ZERO)
		Close(file);

	prompt("Deleting 'empty_file' again. Reopening it with MODE_READWRITE");
	delete_file(root,"empty_file");
	file = open_amigados_file(root,"empty_file",MODE_READWRITE);
	if(file != ZERO)
	{
		char * mem;

		mem = malloc(80 * 512);
		if(mem != NULL)
		{
			memset(mem,'#',80 * 512);

			prompt("Writing 80 * 512 bytes to 'empty_file'.");
			Write(file,mem,80 * 512);

			free(mem);
		}

		Close(file);
	}

	prompt("Replacing file 'empty_file' with a really empty file via MODE_NEWFILE");

	file = open_amigados_file(root,"empty_file",MODE_NEWFILE);
	if(file != ZERO)
		Close(file);

	prompt("Deleting 'empty_file'");
	delete_file(root,"empty_file");
}

/****************************************************************************/

void
test13(char *root)
{
	char ** text;
	int num_text_lines;
	char *taken;

	printf("13. Create files, write data to them in different ways.\n");

	text = heine;
	num_text_lines = NUM_ENTRIES(heine);

	taken = malloc((size_t)num_text_lines);
	if(taken != NULL)
	{
		char * chunk;
		int num_bytes_in_text;
		BPTR file;
		int i;

		num_bytes_in_text = 0;
		for(i = 0 ; i < num_text_lines ; i++)
			num_bytes_in_text += strlen(text[i]);

		prompt("Creating file 'line_by_line' with MODE_NEWFILE");

		file = open_amigados_file(root,"line_by_line",MODE_NEWFILE);
		if(file != ZERO)
		{
			for(i = 0 ; i < num_text_lines ; i++)
				Write(file,text[i],strlen(text[i]));

			Close(file);
		}

		chunk = malloc((size_t)(num_bytes_in_text+1));
		if(chunk != NULL)
		{
			prompt("Creating file 'single_chunk' with MODE_NEWFILE");

			file = open_amigados_file(root,"single_chunk",MODE_NEWFILE);
			if(file != ZERO)
			{
				char * str = chunk;

				strcpy(str,"");
				for(i = 0 ; i < num_text_lines ; i++)
					strcat(str,text[i]);

				Write(file,chunk,strlen(chunk));

				Close(file);
			}

			prompt("Creating file 'random_chunk' with MODE_NEWFILE");

			file = open_amigados_file(root,"random_chunk",MODE_NEWFILE);
			if(file != ZERO)
			{
				int still_there;
				int n;

				memset(chunk,'#',(size_t)num_bytes_in_text);

				Write(file,chunk,num_bytes_in_text);

				memset(taken,0,(size_t)num_text_lines);
				still_there = num_text_lines;

				while(still_there > 0)
				{
					n = get_random_number() % num_text_lines;
					if(! taken[n])
					{
						int offset;

						offset = 0;
						for(i = 0 ; i < n ; i++)
							offset += strlen(text[i]);

						Seek(file,offset,OFFSET_BEGINNING);
						Write(file,text[i],strlen(text[i]));

						taken[n] = 1;

						still_there--;
						if(still_there > 0)
							printf("Still %d lines left to write.\n",still_there);
					}
				}

				Close(file);
			}

			prompt("Creating file 'random_grow' with MODE_NEWFILE");

			file = open_amigados_file(root,"random_grow",MODE_NEWFILE);
			if(file != ZERO)
			{
				int still_there;
				int n;

				prompt("Growing size of file");
				SetFileSize(file,num_bytes_in_text,OFFSET_BEGINNING);

				memset(taken,0,(size_t)num_text_lines);
				still_there = num_text_lines;

				while(still_there > 0)
				{
					n = get_random_number() % num_text_lines;
					if(! taken[n])
					{
						int offset;

						offset = 0;
						for(i = 0 ; i < n ; i++)
							offset += strlen(text[i]);

						Seek(file,offset,OFFSET_BEGINNING);
						Write(file,text[i],strlen(text[i]));

						taken[n] = 1;

						still_there--;
						if(still_there > 0)
							printf("Still %d lines left to write.\n",still_there);
					}
				}

				Close(file);
			}

			prompt("Deleting 'single_chunk'");
			delete_file(root,"single_chunk");

			prompt("Deleting 'random_chunk'");
			delete_file(root,"random_chunk");

			prompt("Deleting 'random_grow'");
			delete_file(root,"random_grow");

			free(chunk);
		}

		prompt("Deleting 'line_by_line'");
		delete_file(root,"line_by_line");

		free(taken);
	}
}

/****************************************************************************/

void
test14(char *root)
{
	BPTR file;

	printf("14. Create file, randomly set its size.\n");

	prompt("Creating file 'springy' with MODE_NEWFILE");

	file = open_amigados_file(root,"springy",MODE_NEWFILE);
	if(file != ZERO)
	{
		int len;
		int n;
		int i;

		n = 10 + (get_random_number() % 10);

		printf("File size is to change %d times.\n",n);

		prompt("Beginning to change file size");

		for(i = 0 ; i < n ; i++)
		{
			len = get_random_number() % (72 * 512 * 19);
			printf("Changing size to %d bytes ",len);
			prompt(NULL);

			SetFileSize(file,len,OFFSET_BEGINNING);
		}

		Close(file);

		prompt("Deleting file 'springy'");
		delete_file(root,"springy");
	}
}

/****************************************************************************/

void
test15(char *root)
{
	BPTR lock;
	BPTR another_lock;
	BPTR parent_dir;
	BPTR current_dir;

	printf("15. Lock test.\n");

	prompt("Getting exclusive lock on root dir");
	lock = Lock(root,EXCLUSIVE_LOCK);
	if(lock != ZERO)
		UnLock(lock);

	prompt("Getting shared lock on root dir");
	lock = Lock(root,EXCLUSIVE_LOCK);
	if(lock != ZERO)
	{
		prompt("Changing shared lock to exclusive");
		ChangeMode(CHANGE_LOCK,lock,EXCLUSIVE_LOCK);

		UnLock(lock);
	}

	prompt("Getting shared lock on root dir");
	lock = Lock(root,SHARED_LOCK);

	prompt("Getting parent dir of root dir");
	parent_dir = ParentDir(lock);
	if(parent_dir != ZERO)
		UnLock(parent_dir);

	prompt("Moving to root dir; locking '/'");
	current_dir = CurrentDir(lock);
	another_lock = Lock("/",SHARED_LOCK);
	CurrentDir(current_dir);
	if(another_lock != ZERO)
		UnLock(another_lock);

	prompt("Creating directory 'dir'");
	replace_entry_with_dir(root,"dir");

	prompt("Getting exclusive lock on 'dir'");
	lock = lock_file(root,"dir",EXCLUSIVE_LOCK);

	prompt("Getting parent dir of 'dir'");
	parent_dir = ParentDir(lock);
	if(parent_dir != ZERO)
		UnLock(parent_dir);

	prompt("Getting another exclusive lock on 'dir'");
	another_lock = lock_file(root,"dir",EXCLUSIVE_LOCK);
	if(another_lock != ZERO)
		UnLock(another_lock);

	prompt("Changing type of first lock");
	ChangeMode(CHANGE_LOCK,lock,SHARED_LOCK);

	prompt("Getting another shared lock on 'dir'");
	another_lock = lock_file(root,"dir",SHARED_LOCK);

	prompt("Checking if both locks match");
	SameLock(lock,another_lock);

	prompt("Changing one lock to exclusive");
	ChangeMode(CHANGE_LOCK,lock,EXCLUSIVE_LOCK);

	prompt("Deleting 'dir'");
	delete_file(root,"dir");

	prompt("Dropping locks");
	UnLock(lock);
	UnLock(another_lock);

	prompt("Deleting 'dir'");
	delete_file(root,"dir");
}

/****************************************************************************/

void
test16(char *root)
{
	BPTR current_dir;
	BPTR lock;

	printf("16. Rename and move test.\n");

	prompt("Creating directories 'parent_dir' and 'child_dir'");
	replace_entry_with_dir(root,"parent_dir");
	replace_entry_with_dir(root,"child_dir");

	lock = Lock(root,SHARED_LOCK);

	prompt("Moving 'child_dir' into 'parent_dir'");
	current_dir = CurrentDir(lock);
	Rename("child_dir","parent_dir/child_dir");
	CurrentDir(current_dir);

	prompt("Moving 'parent_dir' into 'child_dir'");
	current_dir = CurrentDir(lock);
	Rename("parent_dir","parent_dir/child_dir/parent_dir");
	CurrentDir(current_dir);

	prompt("Moving 'parent_dir' into 'parent_dir'");
	current_dir = CurrentDir(lock);
	Rename("parent_dir","parent_dir/parent_dir");
	CurrentDir(current_dir);

	prompt("Moving 'child_dir' into root");
	current_dir = CurrentDir(lock);
	Rename("parent_dir/child_dir","child_dir");
	CurrentDir(current_dir);

	prompt("Creating file 'file'");
	replace_entry_with_file(root,"file");

	prompt("Moving 'child_dir' into 'file'");
	current_dir = CurrentDir(lock);
	Rename("child_dir","file/child_dir");
	CurrentDir(current_dir);

	prompt("Moving 'file' into 'file'");
	current_dir = CurrentDir(lock);
	Rename("file","file/file");
	CurrentDir(current_dir);

	UnLock(lock);

	prompt("Deleting files and directories");
	delete_file(root,"parent_dir");
	delete_file(root,"child_dir");
	delete_file(root,"file");
}

/****************************************************************************/

void
test17(char *root)
{
	BPTR lock;

	printf("17. Directory scanning test.\n");

	prompt("Creating directory 'empty'");
	replace_entry_with_dir(root,"empty");

	lock = lock_file(root,"empty",SHARED_LOCK);
	if(lock != ZERO)
	{
		D_S(struct FileInfoBlock,fib);

		prompt("Examine empty directory");

		if(Examine(lock,fib))
		{
			int i;

			prompt("Scan empty directory");

			for(i = 0 ; i < 3 ; i++)
				ExNext(lock,fib);
		}

		UnLock(lock);
	}

	prompt("Delete directory 'empty'");
	delete_file(root,"empty");
}

/****************************************************************************/

void
test18(char *root)
{
	struct List list;
	struct Node * last_node;
	struct Node * n;
	BPTR lock;
	int count;
	int half;
	int i;

	printf("18. Create random directory entries, rename all of them.\n");

	count = get_random_number() % (72 * 2) + 72;
	if((count & 1) != 0)
		count++;

	half = count / 2;
	printf("Creating %d random directories ",half);
	prompt(NULL);

	NewList(&list);
	last_node = NULL;

	for(i = 0 ; i < count ; i++)
	{
		n = create_keyword_node();
		if(n != NULL)
		{
			AddTail(&list,n);
			if(i < half)
			{
				replace_entry_with_dir(root,n->ln_Name);
				last_node = n;
			}
		}
	}

	prompt("Getting lock on root directory");
	lock = Lock(root,SHARED_LOCK);
	if(lock != ZERO)
	{
		struct Node * more = last_node->ln_Succ;
		BPTR current_dir;
		int quarter = half/2;

		current_dir = CurrentDir(lock);

		n = list.lh_Head;
		while(more->ln_Succ != NULL && n->ln_Succ != NULL)
		{
			if(quarter > 0 && (--quarter) == 0)
				prompt("Half the files renamed");

			printf("Rename '%s' to '%s'\n",n->ln_Name,more->ln_Name);

			Rename(n->ln_Name,more->ln_Name);

			more = more->ln_Succ;
			n = n->ln_Succ;
		}

		CurrentDir(current_dir);

		UnLock(lock);
	}

	prompt("Deleting directories");
	for(n = last_node->ln_Succ ;
	    n->ln_Succ != NULL ;
	    n = n->ln_Succ)
	{
		delete_file(root,n->ln_Name);
	}
}

/****************************************************************************/

void
test19(char *root)
{
	char ** text;
	int num_text_lines;
	BPTR out1;
	BPTR in1;
	BPTR out2;

	printf("19. Producer and consumer.\n");

	text = carroll;
	num_text_lines = NUM_ENTRIES(carroll);

	prompt("Creating 'source' and 'sink'");
	out1 = open_amigados_file(root,"source",MODE_READWRITE);
	in1 = open_amigados_file(root,"source",MODE_READWRITE);
	out2 = open_amigados_file(root,"sink",MODE_NEWFILE);

	if(out1 != ZERO && in1 != ZERO && out2 != ZERO)
	{
		char big_line[512];
		int len;
		int i;

		for(i = 0 ; i < num_text_lines ; i++)
		{
			len = strlen(text[i]);

			Write(out1,text[i],len);

			if(Read(in1,big_line,len) == len)
				Write(out2,big_line,len);
		}
	}

	if(out1 != ZERO)
		Close(out1);

	if(in1 != ZERO)
		Close(in1);

	if(out2 != ZERO)
		Close(out2);

	prompt("Deleting 'source' and 'sink'");
	delete_file(root,"source");
	delete_file(root,"sink");
}

/****************************************************************************/

int
main(int argc,char ** argv)
{
	if(argc > 2)
	{
		char * root = argv[1];
		int which = atoi(argv[2]);

		reset_random_seed();

		printf("Test %d on '%s'\n",which,root);

		switch(which)
		{
			case 1:
				test1(root);
				break;

			case 2:
				test2(root);
				break;

			case 3:
				test3(root);
				break;

			case 4:
				test4(root);
				break;

			case 5:
				test5(root);
				break;

			case 6:
				test6(root);
				break;

			case 7:
				test7(root);
				break;

			case 8:
				test8(root);
				break;

			case 9:
				test9(root);
				break;

			case 10:
				test10(root);
				break;

			case 11:
				test11(root);
				break;

			case 12:
				test12(root);
				break;

			case 13:
				test13(root);
				break;

			case 14:
				test14(root);
				break;

			case 15:
				test15(root);
				break;

			case 16:
				test16(root);
				break;

			case 17:
				test17(root);
				break;

			case 18:
				test18(root);
				break;

			case 19:
				test19(root);
				break;

			default:

				printf("No test for case %d.\n",which);
				break;
		}
	}

	return(0);
}
