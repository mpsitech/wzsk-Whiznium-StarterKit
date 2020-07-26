/**
	* \file WzskcmbdDdspub.h
	* DDS publisher based on rti DDS Connext for Wzsk combined daemon (declarations)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

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
		rti::request::Replier<DdsJobWzskIprTrace::setPOn_req,DdsJobWzskIprTrace::setPOn_reply>* replierJobWzskIprTrace_setPOn;
		rti::request::Replier<DdsJobWzskIprTrace::setRoi_req,DdsJobWzskIprTrace::setRoi_reply>* replierJobWzskIprTrace_setRoi;
		rti::request::Replier<DdsJobWzskIprTrace::setRoiNotFull_req,DdsJobWzskIprTrace::setRoiNotFull_reply>* replierJobWzskIprTrace_setRoiNotFull;

		rti::request::Replier<DdsJobWzskIprCorner::setNTarget_req,DdsJobWzskIprCorner::setNTarget_reply>* replierJobWzskIprCorner_setNTarget;
		rti::request::Replier<DdsJobWzskIprCorner::setRoi_req,DdsJobWzskIprCorner::setRoi_reply>* replierJobWzskIprCorner_setRoi;
		rti::request::Replier<DdsJobWzskIprCorner::setRoiNotFull_req,DdsJobWzskIprCorner::setRoiNotFull_reply>* replierJobWzskIprCorner_setRoiNotFull;

		rti::request::Replier<DdsJobWzskActServo::moveto_req,DdsJobWzskActServo::moveto_reply>* replierJobWzskActServo_moveto;
		rti::request::Replier<DdsJobWzskActServo::zero_req,DdsJobWzskActServo::zero_reply>* replierJobWzskActServo_zero;

		rti::request::Replier<DdsJobWzskActLaser::setLeft_req,DdsJobWzskActLaser::setLeft_reply>* replierJobWzskActLaser_setLeft;
		rti::request::Replier<DdsJobWzskActLaser::setRight_req,DdsJobWzskActLaser::setRight_reply>* replierJobWzskActLaser_setRight;
	};

	/**
		* DataWriters
		*/
	class DataWriters {

	public:
		DataWriters();
		~DataWriters();

	public:
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

		dds::topic::Topic<DdsJobWzskIprCorner::flg>* topicJobWzskIprCorner_flg;
		dds::pub::DataWriter<DdsJobWzskIprCorner::flg>* writerJobWzskIprCorner_flg;
		DdsJobWzskIprCorner::flg* JobWzskIprCorner_flg;

		dds::topic::Topic<DdsJobWzskActServo::angleTarget>* topicJobWzskActServo_angleTarget;
		dds::pub::DataWriter<DdsJobWzskActServo::angleTarget>* writerJobWzskActServo_angleTarget;
		DdsJobWzskActServo::angleTarget* JobWzskActServo_angleTarget;

		dds::topic::Topic<DdsJobWzskActLaser::leftRight>* topicJobWzskActLaser_leftRight;
		dds::pub::DataWriter<DdsJobWzskActLaser::leftRight>* writerJobWzskActLaser_leftRight;
		DdsJobWzskActLaser::leftRight* JobWzskActLaser_leftRight;

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

