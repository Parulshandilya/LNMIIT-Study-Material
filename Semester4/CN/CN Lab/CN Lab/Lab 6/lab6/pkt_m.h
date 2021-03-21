//
// Generated file, do not edit! Created by nedtool 5.0 from pkt.msg.
//

#ifndef __PKT_M_H
#define __PKT_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0500
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Enum generated from <tt>pkt.msg:19</tt> by nedtool.
 * <pre>
 * //
 * // TODO generated message class
 * //
 * enum Type
 * {
 * 
 *     DATA = 0;
 *     ACK = 1;
 * }
 * </pre>
 */
enum Type {
    DATA = 0,
    ACK = 1
};

/**
 * Class generated from <tt>pkt.msg:20</tt> by nedtool.
 * <pre>
 * packet Pkt
 * {
 *     int Mid;
 *     int type @enum(Type);
 *     int source;
 *     int destination;
 * }
 * </pre>
 */
class Pkt : public ::omnetpp::cPacket
{
  protected:
    int Mid;
    int type;
    int source;
    int destination;

  private:
    void copy(const Pkt& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Pkt&);

  public:
    Pkt(const char *name=nullptr, int kind=0);
    Pkt(const Pkt& other);
    virtual ~Pkt();
    Pkt& operator=(const Pkt& other);
    virtual Pkt *dup() const {return new Pkt(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual int getMid() const;
    virtual void setMid(int Mid);
    virtual int getType() const;
    virtual void setType(int type);
    virtual int getSource() const;
    virtual void setSource(int source);
    virtual int getDestination() const;
    virtual void setDestination(int destination);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Pkt& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Pkt& obj) {obj.parsimUnpack(b);}


#endif // ifndef __PKT_M_H

