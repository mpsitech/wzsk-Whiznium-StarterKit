/**
	* \file WzskcmbdDdspub.h
	* DDS publisher based on rti DDS Connext for Wzsk combined daemon (declarations)
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
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
		rti::request::Replier<DdsJobWzskIprTrace::setLevel_req,DdsJobWzskIprTrace::setLevel_reply>* replierJobWzskIprTrace_setLevel;
		rti::request::Replier<DdsJobWzskIprTrace::setRoi_req,DdsJobWzskIprTrace::setRoi_reply>* replierJobWzskIprTrace_setRoi;
		rti::request::Replier<DdsJobWzskIprTrace::setRoiNotFull_req,DdsJobWzskIprTrace::setRoiNotFull_reply>* replierJobWzskIprTrace_setRoiNotFull;

		rti::request::Replier<DdsJobWzskIprCorner::setNTarget_req,DdsJobWzskIprCorner::setNTarget_reply>* replierJobWzskIprCorner_setNTarget;
		rti::request::Replier<DdsJobWzskIprCorner::setRoi_req,DdsJobWzskIprCorner::setRoi_reply>* replierJobWzskIprCorner_setRoi;
		rti::request::Replier<DdsJobWzskIprCorner::setRoiNotFull_req,DdsJobWzskIprCorner::setRoiNotFull_reply>* replierJobWzskIprCorner_setRoiNotFull;

		rti::request::Replier<DdsJobWzskActServo::moveto_req,DdsJobWzskActServo::moveto_reply>* replierJobWzskActServo_moveto;
		rti::request::Replier<DdsJobWzskActServo::stop_req,DdsJobWzskActServo::stop_reply>* replierJobWzskActServo_stop;
		rti::request::Replier<DdsJobWzskActServo::turn_req,DdsJobWzskActServo::turn_reply>* replierJobWzskActServo_turn;
		rti::request::Replier<DdsJobWzskActServo::zero_req,DdsJobWzskActServo::zero_reply>* replierJobWzskActServo_zero;

		rti::request::Replier<DdsJobWzskActExposure::setExposure_req,DdsJobWzskActExposure::setExposure_reply>* replierJobWzskActExposure_setExposure;
		rti::request::Replier<DdsJobWzskActExposure::setFocus_req,DdsJobWzskActExposure::setFocus_reply>* replierJobWzskActExposure_setFocus;

		rti::request::Replier<DdsJobWzskActLaser::setLeft_req,DdsJobWzskActLaser::setLeft_reply>* replierJobWzskActLaser_setLeft;
		rti::request::Replier<DdsJobWzskActLaser::setRight_req,DdsJobWzskActLaser::setRight_reply>* replierJobWzskActLaser_setRight;

		rti::request::Replier<DdsJobWzskAcqPtcloud::setDeltaTheta_req,DdsJobWzskAcqPtcloud::setDeltaTheta_reply>* replierJobWzskAcqPtcloud_setDeltaTheta;
		rti::request::Replier<DdsJobWzskAcqPtcloud::setDWork_req,DdsJobWzskAcqPtcloud::setDWork_reply>* replierJobWzskAcqPtcloud_setDWork;
	};

	/**
		* DataWriters
		*/
	class DataWriters {

	public:
		DataWriters();
		~DataWriters();

	public:
		dds::topic::Topic<DdsJobWzskSrcSysinfo::currCh0VoltCh0>* topicJobWzskSrcSysinfo_currCh0VoltCh0;
		dds::pub::DataWriter<DdsJobWzskSrcSysinfo::currCh0VoltCh0>* writerJobWzskSrcSysinfo_currCh0VoltCh0;
		DdsJobWzskSrcSysinfo::currCh0VoltCh0* JobWzskSrcSysinfo_currCh0VoltCh0;

		dds::topic::Topic<DdsJobWzskSrcSysinfo::currCh1VoltCh1>* topicJobWzskSrcSysinfo_currCh1VoltCh1;
		dds::pub::DataWriter<DdsJobWzskSrcSysinfo::currCh1VoltCh1>* writerJobWzskSrcSysinfo_currCh1VoltCh1;
		DdsJobWzskSrcSysinfo::currCh1VoltCh1* JobWzskSrcSysinfo_currCh1VoltCh1;

		dds::topic::Topic<DdsJobWzskSrcSysinfo::currCh2VoltCh2>* topicJobWzskSrcSysinfo_currCh2VoltCh2;
		dds::pub::DataWriter<DdsJobWzskSrcSysinfo::currCh2VoltCh2>* writerJobWzskSrcSysinfo_currCh2VoltCh2;
		DdsJobWzskSrcSysinfo::currCh2VoltCh2* JobWzskSrcSysinfo_currCh2VoltCh2;

		dds::topic::Topic<DdsJobWzskSrcSysinfo::currCh3VoltCh3>* topicJobWzskSrcSysinfo_currCh3VoltCh3;
		dds::pub::DataWriter<DdsJobWzskSrcSysinfo::currCh3VoltCh3>* writerJobWzskSrcSysinfo_currCh3VoltCh3;
		DdsJobWzskSrcSysinfo::currCh3VoltCh3* JobWzskSrcSysinfo_currCh3VoltCh3;

		dds::topic::Topic<DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3>* topicJobWzskSrcSysinfo_loadAllLoadCore0LoadCore1LoadCore2LoadCore3;
		dds::pub::DataWriter<DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3>* writerJobWzskSrcSysinfo_loadAllLoadCore0LoadCore1LoadCore2LoadCore3;
		DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3* JobWzskSrcSysinfo_loadAllLoadCore0LoadCore1LoadCore2LoadCore3;

		dds::topic::Topic<DdsJobWzskSrcSysinfo::temp>* topicJobWzskSrcSysinfo_temp;
		dds::pub::DataWriter<DdsJobWzskSrcSysinfo::temp>* writerJobWzskSrcSysinfo_temp;
		DdsJobWzskSrcSysinfo::temp* JobWzskSrcSysinfo_temp;

		dds::topic::Topic<DdsJobWzskIprTrace::pOnLeftPOnRight>* topicJobWzskIprTrace_pOnLeftPOnRight;
		dds::pub::DataWriter<DdsJobWzskIprTrace::pOnLeftPOnRight>* writerJobWzskIprTrace_pOnLeftPOnRight;
		DdsJobWzskIprTrace::pOnLeftPOnRight* JobWzskIprTrace_pOnLeftPOnRight;

		dds::topic::Topic<DdsJobWzskIprTrace::levelOnLevelOff>* topicJobWzskIprTrace_levelOnLevelOff;
		dds::pub::DataWriter<DdsJobWzskIprTrace::levelOnLevelOff>* writerJobWzskIprTrace_levelOnLevelOff;
		DdsJobWzskIprTrace::levelOnLevelOff* JobWzskIprTrace_levelOnLevelOff;

		dds::topic::Topic<DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy>* topicJobWzskIprTrace_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy;
		dds::pub::DataWriter<DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy>* writerJobWzskIprTrace_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy;
		DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy* JobWzskIprTrace_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy;

		dds::topic::Topic<DdsJobWzskIprTrace::leftRight>* topicJobWzskIprTrace_leftRight;
		dds::pub::DataWriter<DdsJobWzskIprTrace::leftRight>* writerJobWzskIprTrace_leftRight;
		DdsJobWzskIprTrace::leftRight* JobWzskIprTrace_leftRight;

		dds::topic::Topic<DdsJobWzskIprCorner::NTarget>* topicJobWzskIprCorner_NTarget;
		dds::pub::DataWriter<DdsJobWzskIprCorner::NTarget>* writerJobWzskIprCorner_NTarget;
		DdsJobWzskIprCorner::NTarget* JobWzskIprCorner_NTarget;

		dds::topic::Topic<DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy>* topicJobWzskIprCorner_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy;
		dds::pub::DataWriter<DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy>* writerJobWzskIprCorner_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy;
		DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy* JobWzskIprCorner_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy;

		dds::topic::Topic<DdsJobWzskIprCorner::flgShiftScoreMinScoreMax>* topicJobWzskIprCorner_flgShiftScoreMinScoreMax;
		dds::pub::DataWriter<DdsJobWzskIprCorner::flgShiftScoreMinScoreMax>* writerJobWzskIprCorner_flgShiftScoreMinScoreMax;
		DdsJobWzskIprCorner::flgShiftScoreMinScoreMax* JobWzskIprCorner_flgShiftScoreMinScoreMax;

		dds::topic::Topic<DdsJobWzskActServo::angleTarget>* topicJobWzskActServo_angleTarget;
		dds::pub::DataWriter<DdsJobWzskActServo::angleTarget>* writerJobWzskActServo_angleTarget;
		DdsJobWzskActServo::angleTarget* JobWzskActServo_angleTarget;

		dds::topic::Topic<DdsJobWzskActExposure::autoNotManualTexp>* topicJobWzskActExposure_autoNotManualTexp;
		dds::pub::DataWriter<DdsJobWzskActExposure::autoNotManualTexp>* writerJobWzskActExposure_autoNotManualTexp;
		DdsJobWzskActExposure::autoNotManualTexp* JobWzskActExposure_autoNotManualTexp;

		dds::topic::Topic<DdsJobWzskActExposure::focus>* topicJobWzskActExposure_focus;
		dds::pub::DataWriter<DdsJobWzskActExposure::focus>* writerJobWzskActExposure_focus;
		DdsJobWzskActExposure::focus* JobWzskActExposure_focus;

		dds::topic::Topic<DdsJobWzskActLaser::leftRight>* topicJobWzskActLaser_leftRight;
		dds::pub::DataWriter<DdsJobWzskActLaser::leftRight>* writerJobWzskActLaser_leftRight;
		DdsJobWzskActLaser::leftRight* JobWzskActLaser_leftRight;

		dds::topic::Topic<DdsJobWzskAcqPtcloud::deltaTheta>* topicJobWzskAcqPtcloud_deltaTheta;
		dds::pub::DataWriter<DdsJobWzskAcqPtcloud::deltaTheta>* writerJobWzskAcqPtcloud_deltaTheta;
		DdsJobWzskAcqPtcloud::deltaTheta* JobWzskAcqPtcloud_deltaTheta;

		dds::topic::Topic<DdsJobWzskAcqPtcloud::dWork>* topicJobWzskAcqPtcloud_dWork;
		dds::pub::DataWriter<DdsJobWzskAcqPtcloud::dWork>* writerJobWzskAcqPtcloud_dWork;
		DdsJobWzskAcqPtcloud::dWork* JobWzskAcqPtcloud_dWork;

		dds::topic::Topic<DdsJobWzskAcqPtcloud::xYZ>* topicJobWzskAcqPtcloud_xYZ;
		dds::pub::DataWriter<DdsJobWzskAcqPtcloud::xYZ>* writerJobWzskAcqPtcloud_xYZ;
		DdsJobWzskAcqPtcloud::xYZ* JobWzskAcqPtcloud_xYZ;

		dds::topic::Topic<DdsJobWzskAcqPreview::gray>* topicJobWzskAcqPreview_gray;
		dds::pub::DataWriter<DdsJobWzskAcqPreview::gray>* writerJobWzskAcqPreview_gray;
		DdsJobWzskAcqPreview::gray* JobWzskAcqPreview_gray;

		dds::topic::Topic<DdsJobWzskAcqPreview::redGreenBlue>* topicJobWzskAcqPreview_redGreenBlue;
		dds::pub::DataWriter<DdsJobWzskAcqPreview::redGreenBlue>* writerJobWzskAcqPreview_redGreenBlue;
		DdsJobWzskAcqPreview::redGreenBlue* JobWzskAcqPreview_redGreenBlue;
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
