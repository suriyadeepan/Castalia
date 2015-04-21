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

#ifndef ROUTINGTABLE_RT_H
#define ROUTINGTABLE_RT_H

#endif // ROUTINGTABLE_H
#include <string>
#include <list>
#include "CastaliaModule.h"

enum RoutingFlag {
    NOT_DEFINED = 0,
    VALID = 1,
    INVALID = 2,
    REPAIRABLE = 3,
    BEING_REPAIRED = 4,
};

//expiration of enties managed by timers
typedef struct _ROW {
        std::string destinationAddr;
        unsigned long destinationSeqNum;
        bool isDestinationValid;
        RoutingFlag state;
        int hopCount;
        std::string nextHopAddr;
        std::list<std::string>* precursor;

}Entry;

class RoutingTable{
private:
    std::list<Entry>* table;
    Entry* searchByDest(const char* destination);
    Entry* searchByDest(std::string destination);

public:
    RoutingTable();
    ~RoutingTable();
    /* the function will first search an entry row by destination address in the routing
     * table. If it finds one, the function updates the entry with other parameters,
     * otherwise it adds a new entry to the table.
     */
    void updateEntry(Entry& e);
    void updateEntry(const std::string& destinationAddr,unsigned long destinationSeqNum,
                     bool isDestinationValid,RoutingFlag state,int hopCount,
                     const std::string& nextHopAddr,std::list<std::string>* precursor);
    void updateEntry(const char* destinationAddr,unsigned long destinationSeqNum,
                     bool isDestinationValid,RoutingFlag state,int hopCount,
                     const char* nextHopAddr,std::list<std::string>* precursor);

    /* the function will first search an entry row by destination address in the routing
     * table. If it finds one, the function updates the state field in the entry,
     * otherwise it does nothing.
     */
    void updateState(const std::string& destAddr, RoutingFlag st);
    void updateState(const char* destAddr, RoutingFlag st);

    /* the function will first search an entry row by destination address in the routing
     * table. If it finds one, the function return the nexthop address recorded in the entry,
     * otherwise it returns NULL.
     */
    const char* getNextHop(const char* destination);

    /* the function will first search an entry row by destination address in the routing
     * table. If it finds one, the function return the destination sequence number recorded
     * in the entry, otherwise it returns 0.
     */
    unsigned long getDestSeqNum(const char* destination);

    bool isDestSeqNumValid(const char* destination);
    RoutingFlag getState(const char* destination);
    int getHopCount(const char* destination);
    const std::list<std::string>& getPrecursors(const char* destination);
    void updatePrecursor(const char* destination, const char* precursor);
    void deletePrecursor(const char* destination, const char* precursor);
    void updateSeqNum(const char* destination, unsigned long seq);

    bool isRouteValid(const char* destination);

    void reportLinkBroken(const char* neib, std::list<std::string>* affectedDest, std::list<std::string>* affectedPrecursor);
    void forwardLinkBroken(const char* src, const std::list<std::string>* affectedDest, std::list<std::string>* affectedPrecursor);
};


