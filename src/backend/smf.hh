/*
 * mididings
 *
 * Copyright (C) 2008-2014  Dominic Sacré  <dominic.sacre@gmx.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#ifndef MIDIDINGS_BACKEND_SMF_HH
#define MIDIDINGS_BACKEND_SMF_HH

#include "backend/base.hh"
#include "midi_event.hh"

#include <string>
#include <boost/shared_ptr.hpp>

#include <smf.h>


namespace mididings {
namespace backend {


class SMFBackend
  : public BackendBase
{
  public:
    SMFBackend(std::string const & infile, std::string const & outfile);

    virtual void start(InitFunction init, CycleFunction cycle);
    virtual void stop() { }

    virtual bool input_event(MidiEvent & ev);
    virtual void output_event(MidiEvent const & ev);

    // not implemented
    virtual void finish() { }

    virtual std::size_t num_out_ports() const { return _smf_in->number_of_tracks; }

  private:
    boost::shared_ptr<smf_t> _smf_in;
    boost::shared_ptr<smf_t> _smf_out;

    std::string _outfile;
};


} // backend
} // mididings


#endif // MIDIDINGS_BACKEND_SMF_HH