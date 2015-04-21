/***********************************************************************************************
 *  Copyright (c) Federal University of Para, brazil - 2012                                    *
 *  Developed at the Research Group on Computer Network and Multimedia Communication (GERCOM)  *
 *  All rights reserved                                                                        *
 *                                                                                             *
 *  Permission to use, copy, modify, and distribute this protocol and its documentation for    *
 *  any purpose, without fee, and without written agreement is hereby granted, provided that   *
 *  the above copyright notice, and the author appear in all copies of this protocol.          *
 *                                                                                             *
 *  Author(s): C. Perkins                                                                      *
 *  Reference Paper: RFC 3561                                                                  *
 *  Implementarion: Thiago Fernandes <thiago.oliveira@itec.ufpa.br> <thiagofdso.ufpa@gmail.com>* 
 **********************************************************************************************/

#include "RoutingTable_rt.h"

using namespace std;

RoutingTable::RoutingTable(){
    table = new list<Entry>();
}

RoutingTable::~RoutingTable(){
    for(list<Entry>::iterator i=table->begin();i!=table->end();++i){
        Entry &e = *i;
        if ((e.precursor)!=NULL){
            delete (e.precursor);
        }

    }
    delete table;
}

Entry* RoutingTable::searchByDest(std::string destination){
    for(list<Entry>::iterator i=table->begin();i!=table->end();++i){
        Entry& ec = *i;
        if(ec.destinationAddr==destination){
            return &ec;
        }
    }
    return NULL;
}
Entry* RoutingTable::searchByDest(const char* destination){
    string s(destination);
    return RoutingTable::searchByDest(s);
}

void RoutingTable::updateEntry(Entry& e){
    Entry* ec = RoutingTable::searchByDest(e.destinationAddr);
    if(ec && (!(ec->state==VALID)||(ec->destinationSeqNum < e.destinationSeqNum)||
    		((ec->destinationSeqNum = e.destinationSeqNum)&&(ec->hopCount > e.hopCount)))){
            ec->destinationSeqNum = e.destinationSeqNum;
            ec->hopCount = e.hopCount;
            ec->isDestinationValid = e.isDestinationValid;
            ec->nextHopAddr = e.nextHopAddr;
            ec->precursor->merge(*(e.precursor));
            ec->state = e.state;
        } else if(!ec){
        table->push_back(e);
    }

}

void RoutingTable::updateEntry(const string& destinationAddr,unsigned long destinationSeqNum,
                               bool isDestinationValid,RoutingFlag state,int hopCount,
                               const string& nextHopAddr,list<string>* precursor){
    Entry e;
    e.destinationAddr = destinationAddr;
    e.destinationSeqNum = destinationSeqNum;
    e.hopCount = hopCount;
    e.isDestinationValid = isDestinationValid;
    e.nextHopAddr = nextHopAddr;
    e.precursor = new list<string>();
    if(precursor != NULL){
        e.precursor->merge(*precursor);
    }
    e.state = state;
    RoutingTable::updateEntry(e);
}

void RoutingTable::updateEntry(const char *destinationAddr, unsigned long destinationSeqNum,
                               bool isDestinationValid, RoutingFlag state, int hopCount,
                               const char *nextHopAddr, std::list<std::string> *precursor){
    string destAddr(destinationAddr);
    string nextHop(nextHopAddr);
    RoutingTable::updateEntry(destAddr,destinationSeqNum,isDestinationValid,state,hopCount,nextHop,precursor);
}

void RoutingTable::updateState(const string& destAddr,RoutingFlag st){
    for(list<Entry>::iterator i=table->begin();i!=table->end();++i){
        Entry& ec = *i;
        if(ec.destinationAddr==destAddr){
            ec.state = st;
            break;
        }
    }
}

void RoutingTable::updateState(const char* destAddr, RoutingFlag st){
    RoutingTable::updateState(string(destAddr), st);
}

const char* RoutingTable::getNextHop(const char* destination){
    Entry *e = RoutingTable::searchByDest(destination);
    if(e /*&& e->state==VALID*/){
        return e->nextHopAddr.c_str();
    }
    else return NULL;
}

unsigned long RoutingTable::getDestSeqNum(const char* destination){
    Entry *e = RoutingTable::searchByDest(destination);
    if(e){
        return e->destinationSeqNum;
    }
    else return 0;
}

bool RoutingTable::isDestSeqNumValid(const char* destination){
    Entry *e = RoutingTable::searchByDest(destination);
    if(e){
        return e->isDestinationValid;
    }
    else return false;
}

RoutingFlag RoutingTable::getState(const char* destination){
    Entry *e = RoutingTable::searchByDest(destination);
    if(e){
        return e->state;
    }
    else return NOT_DEFINED;
}

int RoutingTable::getHopCount(const char* destination){
    Entry *e = RoutingTable::searchByDest(destination);
    if(e){
        return e->hopCount;
    }
    else return 0;
}

const std::list<string>& RoutingTable::getPrecursors(const char* destination){
    Entry *e = RoutingTable::searchByDest(destination);
    if(e){
        return *(e->precursor);
    }
    else return *(new list<string>());
}

void RoutingTable::updatePrecursor(const char* destination, const char* precursor){
    string destAddr = string(destination);
    string pre = string(precursor);
    for(list<Entry>::iterator i=table->begin();i!=table->end();++i){
        Entry& ec = *i;
        if(ec.destinationAddr==destAddr){
            for(list<string>::iterator j = ec.precursor->begin();j!=ec.precursor->end();++j){
                string curr = *j;
                if(pre==curr) return;
            }
            ec.precursor->push_back(pre);
            break;
        }
    }
}

void RoutingTable::deletePrecursor(const char* destination, const char* precursor){
    string destAddr = string(destination);
    string pre = string(precursor);
    for(list<Entry>::iterator i=table->begin();i!=table->end();++i){
        Entry& ec = *i;
        if(ec.destinationAddr==destAddr){
            ec.precursor->remove(pre);
            break;
        }
    }
}

bool RoutingTable::isRouteValid(const char* destination){
    string destAddr = string(destination);
    for(list<Entry>::iterator i=table->begin();i!=table->end();++i){
        Entry& ec = *i;
        if(ec.destinationAddr==destAddr){
            if(ec.state==VALID){
                return true;
            }
        }
    }
    return false;
}

void RoutingTable::reportLinkBroken(const char* neib, list<string>* affectedDest, list<string>* affectedPrecursor){
    for(list<Entry>::iterator i=table->begin();i!=table->end();++i){
        Entry& ec = *i;
        if(ec.nextHopAddr.compare(neib)==0 && ec.state==VALID){
            ec.state=INVALID;
        	ec.destinationSeqNum++;
            affectedPrecursor->insert(affectedPrecursor->begin(),ec.precursor->begin(),ec.precursor->end());
            affectedDest->push_front(ec.destinationAddr);
        }
    }
    affectedDest->unique();
    affectedPrecursor->unique();
}

void RoutingTable::forwardLinkBroken(const char* src, const list<string>* affectedDest, std::list<std::string>* affectedPrecursor){
    for(list<string>::const_iterator i=affectedDest->begin();i!=affectedDest->end();++i){
        string s = *i;
        Entry* e = searchByDest(s);
        if(e && e->state==VALID && e->nextHopAddr.compare(src)==0){
            e->state=INVALID;
            affectedPrecursor->insert(affectedPrecursor->begin(),e->precursor->begin(),e->precursor->end());
        }
    }
    affectedPrecursor->unique();
}

void RoutingTable::updateSeqNum(const char* destination, unsigned long seq){
	Entry *e = RoutingTable::searchByDest(destination);
	if(e && e->destinationSeqNum < seq){
	    e->destinationSeqNum = seq;
	}
}




