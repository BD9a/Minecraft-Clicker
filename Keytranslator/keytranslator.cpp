#include "keytranslator.h"

KeyTranslator::KeyTranslator(QObject *parent) : QObject(parent){
    add("SPACE", 32);
    add("A", 65);
    add("B", 66);
    add("C", 67);
    add("D", 68);
    add("E", 69);
    add("F", 70);
    add("G", 71);
    add("H", 72);
    add("I", 73);
    add("J", 74);
    add("K", 75);
    add("L", 76);
    add("M", 77);
    add("N", 78);
    add("O", 79);
    add("P", 80);
    add("Q", 81);
    add("R", 82);
    add("S", 83);
    add("T", 84);
    add("U", 85);
    add("V", 86);
    add("W", 87);
    add("X", 88);
    add("Y", 89);
    add("Z", 90);
    add("ALT", 18);
}



int KeyTranslator::getCode(QString key){
    QMapIterator<QString, int> i(keyCodes);
    while (i.hasNext()) {
        i.next();
        if(key == i.key()){
            return i.value();
        }
    }
    return 404;
}

QString KeyTranslator::getKey(int code)
{
    QMapIterator<QString, int> i(keyCodes);
    while (i.hasNext()) {
        if(code == i.value()){
            return i.key();
        }
    }
    return "404";
}

void KeyTranslator::add(QString v0, int v1){
    keyCodes.insert(v0,v1);
}

