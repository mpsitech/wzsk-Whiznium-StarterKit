/**
	* \file WzskcmbdDdspub.h
	* DDS publisher based on rti DDS Connext for Wzsk combined daemon (declarations)
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
  */
// IP header --- ABOVE

#ifndef WZSKCMBDDDSPUB_H
#define WZSKCMBDDDSPUB_H

#include "RootWzsk.h"

#include <dds/dds.hpp>
#include <rti/request/rtirequest.hpp>

#include "DdsWzsk.hpp"

/**
	* WzskcmbdDdspub
	*/
namespace WzskcmbdDdspub {
	/**
		* Repliers
		*/
	class Repliers {

	public:
		Repliers();
		~Repliers();

	public:
		rti::request::Replier<DdsJobWzskAcqCorner::setRoi_req,DdsJobWzskAcqCorner::setRoi_reply>* replierJobWzskAcqCorner_setRoi;

		rti::request::Replier<DdsJobWzskAcqTrace::setRoi_req,DdsJobWzskAcqTrace::setRoi_reply>* replierJobWzskAcqTrace_setRoi;

		rti::request::Replier<DdsJobWzskActLaser::setLeft_req,DdsJobWzskActLaser::setLeft_reply>* replierJobWzskActLaser_setLeft;
		rti::request::Replier<DdsJobWzskActLaser::setRight_req,DdsJobWzskActLaser::setRight_reply>* replierJobWzskActLaser_setRight;

		rti::request::Replier<DdsJobWzskActRotary::moveto_req,DdsJobWzskActRotary::moveto_reply>* replierJobWzskActRotary_moveto;
		rti::request::Replier<DdsJobWzskActRotary::stop_req,DdsJobWzskActRotary::stop_reply>* replierJobWzskActRotary_stop;
		rti::request::Replier<DdsJobWzskActRotary::turn_req,DdsJobWzskActRotary::turn_reply>* replierJobWzskActRotary_turn;
		rti::request::Replier<DdsJobWzskActRotary::zero_req,DdsJobWzskActRotary::zero_reply>* replierJobWzskActRotary_zero;
	};

	/**
		* DataWriters
		*/
	class DataWriters {

	public:
		DataWriters();
		~DataWriters();

	public:
		dds::topic::Topic<DdsJobWzskAcqCorner::roiX0RoiY0RoiX1RoiY1>* topicJobWzskAcqCorner_roiX0RoiY0RoiX1RoiY1;
		dds::pub::DataWriter<DdsJobWzskAcqCorner::roiX0RoiY0RoiX1RoiY1>* writerJobWzskAcqCorner_roiX0RoiY0RoiX1RoiY1;
		DdsJobWzskAcqCorner::roiX0RoiY0RoiX1RoiY1* JobWzskAcqCorner_roiX0RoiY0RoiX1RoiY1;

		dds::topic::Topic<DdsJobWzskAcqCorner::shiftScoreMinScoreMax>* topicJobWzskAcqCorner_shiftScoreMinScoreMax;
		dds::pub::DataWriter<DdsJobWzskAcqCorner::shiftScoreMinScoreMax>* writerJobWzskAcqCorner_shiftScoreMinScoreMax;
		DdsJobWzskAcqCorner::shiftScoreMinScoreMax* JobWzskAcqCorner_shiftScoreMinScoreMax;

		dds::topic::Topic<DdsJobWzskAcqTrace::roiX0RoiY0RoiX1RoiY1>* topicJobWzskAcqTrace_roiX0RoiY0RoiX1RoiY1;
		dds::pub::DataWriter<DdsJobWzskAcqTrace::roiX0RoiY0RoiX1RoiY1>* writerJobWzskAcqTrace_roiX0RoiY0RoiX1RoiY1;
		DdsJobWzskAcqTrace::roiX0RoiY0RoiX1RoiY1* JobWzskAcqTrace_roiX0RoiY0RoiX1RoiY1;

		dds::topic::Topic<DdsJobWzskActLaser::leftRight>* topicJobWzskActLaser_leftRight;
		dds::pub::DataWriter<DdsJobWzskActLaser::leftRight>* writerJobWzskActLaser_leftRight;
		DdsJobWzskActLaser::leftRight* JobWzskActLaser_leftRight;

		dds::topic::Topic<DdsJobWzskActRotary::angleTarget>* topicJobWzskActRotary_angleTarget;
		dds::pub::DataWriter<DdsJobWzskActRotary::angleTarget>* writerJobWzskActRotary_angleTarget;
		DdsJobWzskActRotary::angleTarget* JobWzskActRotary_angleTarget;

		dds::topic::Topic<DdsJobWzskSrcFpgainfo::hdrDRdHdrDWr>* topicJobWzskSrcFpgainfo_hdrDRdHdrDWr;
		dds::pub::DataWriter<DdsJobWzskSrcFpgainfo::hdrDRdHdrDWr>* writerJobWzskSrcFpgainfo_hdrDRdHdrDWr;
		DdsJobWzskSrcFpgainfo::hdrDRdHdrDWr* JobWzskSrcFpgainfo_hdrDRdHdrDWr;

		dds::topic::Topic<DdsJobWzskSrcFpgainfo::rndDRdRndDWr>* topicJobWzskSrcFpgainfo_rndDRdRndDWr;
		dds::pub::DataWriter<DdsJobWzskSrcFpgainfo::rndDRdRndDWr>* writerJobWzskSrcFpgainfo_rndDRdRndDWr;
		DdsJobWzskSrcFpgainfo::rndDRdRndDWr* JobWzskSrcFpgainfo_rndDRdRndDWr;

		dds::topic::Topic<DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3>* topicJobWzskSrcSysinfo_loadAllLoadCore0LoadCore1LoadCore2LoadCore3;
		dds::pub::DataWriter<DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3>* writerJobWzskSrcSysinfo_loadAllLoadCore0LoadCore1LoadCore2LoadCore3;
		DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3* JobWzskSrcSysinfo_loadAllLoadCore0LoadCore1LoadCore2LoadCore3;

		dds::topic::Topic<DdsJobWzskSrcSysinfo::temp>* topicJobWzskSrcSysinfo_temp;
		dds::pub::DataWriter<DdsJobWzskSrcSysinfo::temp>* writerJobWzskSrcSysinfo_temp;
		DdsJobWzskSrcSysinfo::temp* JobWzskSrcSysinfo_temp;
	};

	void* run(void* arg);
	void cleanup(void* arg);

	void runMethod(const Sbecore::ubigint jref, const Sbecore::uint ixWzskVFeatgroup, const std::string& srefIxVMethod, const std::vector<const void*>& parsInv, const std::vector<void*>& parsRet);

	extern XchgWzskcmbd* xchg;
	extern Sbecore::ubigint jrefM2msess;
	extern M2msessWzsk::StatShr statshr;
	extern Repliers repliers;
	extern DataWriters dataWriters;
};

#endif
