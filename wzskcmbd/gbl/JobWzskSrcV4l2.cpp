/**
	* \file JobWzskSrcV4l2.cpp
	* job handler for job JobWzskSrcV4l2 (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "JobWzskSrcV4l2.h"

#include "JobWzskSrcV4l2_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

// IP ns.spec --- INSERT

// IP Shrdat.subs --- IBEGIN
/******************************************************************************
 class JobWzskSrcV4l2::Shrdat::ResultitemAcq
 ******************************************************************************/

JobWzskSrcV4l2::Shrdat::ResultitemAcq::ResultitemAcq(
			XchgWzsk* xchg
			, int fd
			, const uint ix
		) {
	bool success;

	buf = NULL;

	struct v4l2_buffer v4l2buf = {0};

	v4l2buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	v4l2buf.memory = V4L2_MEMORY_MMAP;
	v4l2buf.index = ix;

	while (true) {
		success = (ioctl(fd, VIDIOC_QUERYBUF, &v4l2buf) != -1);
		if (success) break;

		if (errno != EINTR) throw WzskException(WzskException::V4L2, {{"msg","error querying buffer at index " + to_string(ix) + " (" + string(strerror(errno)) + ")"}});
	};

	if (success) {
		buf = mmap(NULL, v4l2buf.length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, v4l2buf.m.offset);
		sizeBuf = v4l2buf.length;
	};

	t = 0.0;

	rgb16len = xchg->stgwzskframegeo.wRgb * xchg->stgwzskframegeo.hRgb;
	r16 = new uint16_t[rgb16len];
	g16 = new uint16_t[rgb16len];
	b16 = new uint16_t[rgb16len];

	grrd16len = xchg->stgwzskframegeo.wGrrd * xchg->stgwzskframegeo.hGrrd;
	gr16 = new uint16_t[grrd16len];
	rd16 = new uint16_t[grrd16len];
};

JobWzskSrcV4l2::Shrdat::ResultitemAcq::~ResultitemAcq() {
	if (buf) munmap(buf, sizeBuf);

	delete[] r16;
	delete[] g16;
	delete[] b16;

	delete[] gr16;
	delete[] rd16;
};

void JobWzskSrcV4l2::Shrdat::ResultitemAcq::updateT(
			int fd
			, const uint ix
		) {
	bool success;

	struct v4l2_buffer v4l2buf = {0};

	v4l2buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	v4l2buf.memory = V4L2_MEMORY_MMAP;
	v4l2buf.index = ix;

	while (true) {
		success = (ioctl(fd, VIDIOC_QUERYBUF, &v4l2buf) != -1);
		if (success) break;

		if (errno != EINTR) throw WzskException(WzskException::V4L2, {{"msg","error querying buffer at index " + to_string(ix) + " (" + string(strerror(errno)) + ")"}});
	};

	t = (((double) v4l2buf.timestamp.tv_sec) + 1.0e-6*((double) v4l2buf.timestamp.tv_usec)); // end-of-exposure time stamp
};

/******************************************************************************
 class JobWzskSrcV4l2::Shrdat::ResultAcq
 ******************************************************************************/

JobWzskSrcV4l2::Shrdat::ResultAcq::ResultAcq() : Result() {
	fd = 0;
};

JobWzskSrcV4l2::Shrdat::ResultAcq::~ResultAcq() {
};

void JobWzskSrcV4l2::Shrdat::ResultAcq::queue(
			const uint ix
		) {
	bool success;

	v4l2_buffer v4l2buf = {0};

	v4l2buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	v4l2buf.memory = V4L2_MEMORY_MMAP;
	v4l2buf.index = ix;

	while (true) {
		success = (ioctl(fd, VIDIOC_QBUF, &v4l2buf) != -1);
		if (success) break;

		if (!success) throw WzskException(WzskException::V4L2, {{"msg","error queuing buffer (" + string(strerror(errno)) + ")"}});
	};

	if (success) Result::queue(ix);
};

bool JobWzskSrcV4l2::Shrdat::ResultAcq::dequeue(
			uint& ix
		) {
	// combined v4l2buf / result action

	bool success;

	v4l2_buffer v4l2buf = {0};

	v4l2buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	v4l2buf.memory = V4L2_MEMORY_MMAP;

	while (true) {
		success = (ioctl(fd, VIDIOC_DQBUF, &v4l2buf) != -1);
		if (success) break;

		if (!success) throw WzskException(WzskException::V4L2, {{"msg","error de-queuing buffer (" + string(strerror(errno)) + ")"}});
	};

	if (success) {
		mAccess.lock("ResultAcq", "dequeue");

		success = false;

		for (auto it = icsQueue.begin(); it != icsQueue.end(); it++) {
			if (*it == v4l2buf.index) {
				ix = *it;
				icsQueue.erase(it);

				success = true;

				break;
			};
		};

		mAccess.unlock("ResultAcq", "dequeue");

		if (!success) {
			while (true) {
				success = (ioctl(fd, VIDIOC_QBUF, &v4l2buf) != -1);
				if (success) break;

				if (errno != EINTR) throw WzskException(WzskException::V4L2, {{"msg","error queuing buffer (" + string(strerror(errno)) + ")"}});
			};

			success = false;
		};
	};

	return success;
};

void JobWzskSrcV4l2::Shrdat::ResultAcq::requeueAllV4l2() {
	v4l2_buffer v4l2buf = {0};

	v4l2buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	v4l2buf.memory = V4L2_MEMORY_MMAP;

	for (v4l2buf.index = 0; v4l2buf.index < size(); v4l2buf.index++) ioctl(fd, VIDIOC_QBUF, &v4l2buf);
};
// IP Shrdat.subs --- IEND

/******************************************************************************
 class JobWzskSrcV4l2::Shrdat
 ******************************************************************************/

JobWzskSrcV4l2::Shrdat::Shrdat() :
			ShrdatWzsk("JobWzskSrcV4l2", "Shrdat")
		{
};

void JobWzskSrcV4l2::Shrdat::init(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
		) {
	// IP Shrdat.init --- IBEGIN
	bool success;

	if ((xchg->stgwzskglobal.ixWzskVTarget != VecWzskVTarget::APALIS) && (xchg->stgwzskglobal.ixWzskVTarget != VecWzskVTarget::WS)) return;

	v4l2_format fmt;
	v4l2_streamparm parm;
	v4l2_frmsizeenum fszenum;
	v4l2_requestbuffers req;

	const unsigned int N = 8; // eight buffers and result items prove to work nicely

	fd = -1;

	try {
		// open camera
		fd = open(stg.path.c_str(), O_RDWR);

		success = (fd != -1);
		if (!success) throw WzskException(WzskException::V4L2, {{"msg","error connecting to camera"}});

		resultAcq.fd = fd;

		if (success) {
			// limit to 15fps
			memset(&parm, 0, sizeof(parm));

			parm.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

			parm.parm.capture.timeperframe.numerator = 1;
			parm.parm.capture.timeperframe.denominator = 15; // actual frame rate always ends up being 7.5Hz

			if (xchg->stgwzskglobal.ixWzskVTarget == VecWzskVTarget::APALIS) {
				parm.parm.capture.capturemode = 6; // 2592 x 1944 works after gstreamer changes some settings
				//parm.parm.capture.capturemode = 8; // 1024 x 768 works with YUYV
			} else if (xchg->stgwzskglobal.ixWzskVTarget == VecWzskVTarget::WS) {
				parm.parm.capture.capturemode = 5; // 1600 x 1200 YUYV
			};

			while (true) {
				success = (ioctl(fd, VIDIOC_S_PARM, &parm) != -1);
				if (success) break;

				if (errno != EINTR) throw WzskException(WzskException::V4L2, {{"msg","error setting frame rate (" + string(strerror(errno)) + ")"}});
			};
		};

		if (success) {
			// initialize image format by get ioctl
			memset(&fmt, 0, sizeof(fmt));

			fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

			while (true) {
				success = (ioctl(fd, VIDIOC_G_FMT, &fmt) != -1);
				if (success) break;

				if (errno != EINTR) throw WzskException(WzskException::V4L2, {{"msg","error initializing image format (" + string(strerror(errno)) + ")"}});
			};
		};
		
		if (success) {
			// validate width & height
			memset(&fszenum, 0, sizeof(fszenum));

			if (xchg->stgwzskglobal.ixWzskVTarget == VecWzskVTarget::APALIS) fszenum.index = 6;
			else if (xchg->stgwzskglobal.ixWzskVTarget == VecWzskVTarget::WS) fszenum.index = 5;

			if (!stg.YUV422NotYUV420) fszenum.pixel_format = V4L2_PIX_FMT_YUV420;
			else fszenum.pixel_format = V4L2_PIX_FMT_YUYV; // VecWzskVTarget::WS only works with this

			while (true) {
				success = (ioctl(fd, VIDIOC_ENUM_FRAMESIZES, &fszenum) != -1);
				if (success) break;

				if (errno != EINTR) throw WzskException(WzskException::V4L2, {{"msg","error obtaining frame size (" + string(strerror(errno)) + ")"}});
			};

			//cout << "obtained capture size for mode " << fszenum.index << " is " << fszenum.discrete.width << "x" << fszenum.discrete.height << endl;
		};

		if (success) {
			// set image format
			//memset(&fmt, 0, sizeof(fmt));

			fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
			fmt.fmt.pix.bytesperline = 0;
			fmt.fmt.pix.priv = 0;
			fmt.fmt.pix.sizeimage = 0;
			fmt.fmt.pix.width = xchg->stgwzskframegeo.wAcq;
			fmt.fmt.pix.height = xchg->stgwzskframegeo.hAcq;
			if (!stg.YUV422NotYUV420) fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUV420;
			else fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV;
			//fmt.fmt.pix.field = V4L2_FIELD_NONE;

			while (true) {
				success = (ioctl(fd, VIDIOC_S_FMT, &fmt) != -1);
				if (success) break;

				if (errno != EINTR) throw WzskException(WzskException::V4L2, {{"msg","error setting image format (" + string(strerror(errno)) + ")"}});
			};
		};

		//if (success) success = setCtrl(V4L2_CID_HFLIP, "horizontal flip", true, 0, true);
		//if (success) success = setCtrl(V4L2_CID_MXC_VF_ROT, "MXC rotate", false, V4L2_MXC_ROTATE_180, false);
		//if (success) success = setCtrl(V4L2_CID_POWER_LINE_FREQUENCY, "power_line_frequency", false, V4L2_CID_POWER_LINE_FREQUENCY_50HZ, false);
		//if (success) success = setCtrl(V4L2_CID_BACKLIGHT_COMPENSATION, "backlight_compensation", false, 5, false);
		//if (success) success = setCtrl(V4L2_CID_EXPOSURE_AUTO, "exposure_auto", false, V4L2_EXPOSURE_MANUAL, false);
		//if (success) success = setCtrl(V4L2_CID_EXPOSURE_ABSOLUTE, "exposure_absolute", false, 100, false);
		//if (success) success = setCtrl(V4L2_CID_FOCUS_AUTO, "focus_auto", true, 0, false);
		//if (success) success = setCtrl(V4L2_CID_FOCUS_ABSOLUTE, "focus_absolute", false, 10, false);

		if (success) {
			// request buffers
			memset(&req, 0, sizeof(req));

			req.count = N;
			req.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
			req.memory = V4L2_MEMORY_MMAP;

			while (true) {
				success = (ioctl(fd, VIDIOC_REQBUFS, &req) != -1);
				if (success) break;

				if (errno != EINTR) throw WzskException(WzskException::V4L2, {{"msg","error requesting buffers (" + string(strerror(errno)) + ")"}});
			};
		};

		if (success) {
			// map to user space memory and queue (intertwined with result items)
			for (unsigned int i = 0; i < N; i++) resultAcq.append(new ResultitemAcq(xchg, fd, i));
		};

		if (!success && (fd != -1)) {
			close(fd);
			fd = 0;
		};

	} catch (WzskException& e) {
		cout << e.getSquawk(VecWzskVError::getIx, VecWzskVError::getTitle, VecWzskVLocale::ENUS) << endl;
	};

	acq = 0;

	cancelAcq = false;
	// IP Shrdat.init --- IEND
};

void JobWzskSrcV4l2::Shrdat::term(
			XchgWzsk* xchg
		) {
	// IP Shrdat.term --- IBEGIN
	resultAcq.clear(); // relevant in order to remove user space mappings of kernel buffers

	if (fd != -1) {
		close(fd);
		fd = 0;
	};
	// IP Shrdat.term --- IEND
};

/******************************************************************************
 class JobWzskSrcV4l2
 ******************************************************************************/

JobWzskSrcV4l2::JobWzskSrcV4l2(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			CsjobWzsk(xchg, VecWzskVJob::JOBWZSKSRCV4L2, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.spec1 --- INSERT

	// IP constructor.cust2 --- INSERT

	// IP constructor.spec2 --- INSERT

	if (srvNotCli) xchg->addClstn(VecWzskVCall::CALLWZSKCALLBACK, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::WEAK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

JobWzskSrcV4l2::~JobWzskSrcV4l2() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
void* JobWzskSrcV4l2::runAcq(
			void* arg
		) {
	JobWzskSrcV4l2* srv = (JobWzskSrcV4l2*) arg;

	bool success;

	const unsigned int buftype = V4L2_BUF_TYPE_VIDEO_CAPTURE;

	fd_set fds;
	timeval to = {0};

	uint ixRi;
	Shrdat::ResultitemAcq* ri = NULL;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanupAcq, arg);

	FD_ZERO(&fds);
	FD_SET(srv->shrdat.fd, &fds);

	to.tv_sec = 1;

	try {
		// - prepare / start capture
		shrdat.mAcq.lock("JobWzskSrcV4l2", "runAcq[1]");

		try {
			shrdat.resultAcq.requeueAllV4l2(); // make sure all result items are queued, as a previous ioctl(VIDIOC_STREAMOFF) call may have dequeued some of them (only the v4l2 part)

			while (true) {
				success = (ioctl(srv->shrdat.fd, VIDIOC_STREAMON, &buftype) != -1);
				if (success) break;

				if (errno != EINTR) throw WzskException(WzskException::V4L2, {{"msg","error starting capture (" + string(strerror(errno)) + ")"}});
			};

		} catch (WzskException& e) {
			shrdat.cancelAcq = true;

			XchgWzsk::runExtcall(new ExtcallWzsk(srv->xchg, new Call(VecWzskVCall::CALLWZSKCALLBACK, srv->jref, Arg())));

			shrdat.mAcq.unlock("JobWzskSrcV4l2", "runAcq[1]");

			throw;
		};

		shrdat.mAcq.unlock("JobWzskSrcV4l2", "runAcq[2]");

		// - loop
		while (true) {
			if (shrdat.cancelAcq) break;

			success = (select(srv->shrdat.fd + 1, &fds, NULL, NULL, &to) != -1);
			if (!success) throw WzskException(WzskException::V4L2, {{"msg","timeout waiting for frame (" + string(strerror(errno)) + ")"}});

			if (success) success = shrdat.resultAcq.dequeue(ixRi);

			if (success) {
				//cout << "new frame at index " << ixRi << endl;

				ri = (Shrdat::ResultitemAcq*) shrdat.resultAcq[ixRi];

				ri->updateT(srv->shrdat.fd, ixRi);

				XchgWzsk::runExtcall(new ExtcallWzsk(srv->xchg, new Call(VecWzskVCall::CALLWZSKCALLBACK, srv->jref, Arg(ixRi, 0, {}, "acq", 0, 0.0, false, "", Arg::IX + Arg::SREF))));
			};
		};

		// - stop capture
		while (true) {
			success = (ioctl(srv->shrdat.fd, VIDIOC_STREAMOFF, &buftype) != -1);
			if (success) break;

			if (errno != EINTR) throw WzskException(WzskException::V4L2, {{"msg","error stopping capture (" + string(strerror(errno)) + ")"}});
		};

	} catch (WzskException& e) {
		cout << e.getSquawk(VecWzskVError::getIx, VecWzskVError::getTitle, VecWzskVLocale::ENUS) << endl;
	};

	pthread_cleanup_pop(0);

	shrdat.acq = 0;

	return NULL;
};

void JobWzskSrcV4l2::cleanupAcq(
			void* arg
		) {
	shrdat.mAcq.lock("JobWzskSrcV4l2", "cleanupAcq");

	shrdat.acq = 0;

	shrdat.mAcq.unlock("JobWzskSrcV4l2", "cleanupAcq");
};

bool JobWzskSrcV4l2::setCtrl(
			const int id
			, const string& sref
			, const bool boolvalNotIntval
			, const int intval
			, const bool boolval
		) {
	// according to drivers/media/platform/mxc/capture/mxc_v4l2_capture.c, V4L2_CID... controls are recognized
	// _HFLIP, _VFLIP, _MXC_ROT, _MXC_VF_ROT, _HUE, _CONTRAST, _BRIGHTNESS, _SATURATION,
	// _RED_BALANCE, _BLUE_BALANCE, _EXPOSURE
	// ... probably, they are handled by the iMX6's IPU

	// according to drivers/media/platform/mxc/capture/ov5640_mipi.c, V4L2_CID... controls are recognized
	// _BRIGHTNESS, _CONTRAST, _SATURATION, _HUE, _AUTO_WHITE_BALANCE, _DO_WHITE_BALANCE,
	// _RED_BALANCE, _BLUE_BALANCE, _GAMMA, _EXPOSURE, _AUTOGAIN, _GAIN, _HFLIP, _VFLIP
	// ... but for now, don't do anything: this is different in ov5640.c

	// plus, the VIDIOC_S_PARM V4L2_BUF_TYPE_VIDEO_CAPTURE (set streaming parameter) ioctl works

	// after patching mxc_v4l2_capture.c and ov5640_mipi.c, V4L2_CID_EXPOSURE_AUTO, V4L2_CID_EXPOSURE_ABSOLUTE and V4L2_CID_FOCUS_ABSOLUTE should work

	bool success;

	v4l2_control ctrl;

	memset(&ctrl, 0, sizeof(ctrl));
	
	ctrl.id = id;
	if (boolvalNotIntval) ctrl.value = (int) boolval;
	else ctrl.value = intval;

	while (true) {
		success = (ioctl(shrdat.fd, VIDIOC_S_CTRL, &ctrl) != -1);
		if (success) break;

		if (errno != EINTR) throw WzskException(WzskException::V4L2, {{"msg","error setting control parameter " + sref + " (" + string(strerror(errno)) + ")"}});
	};

/*
	// VIDIOC_S_EXT_CTRLS not supported
	bool success;

	v4l2_ext_controls ctrls = {};
	v4l2_ext_control ctrl = {};

	memset(&ctrls, 0, sizeof(ctrls));
	memset(&ctrl, 0, sizeof(ctrl));

	ctrl.id = id;
	if (boolvalNotIntval) ctrl.value = (int) boolval;
	else ctrl.value = intval;

	ctrls.ctrl_class = V4L2_CTRL_ID2CLASS(ctrl.id);
	ctrls.count = 1;
	ctrls.controls = &ctrl;

	while (true) {
		success = (ioctl(shrdat.fd, VIDIOC_S_EXT_CTRLS, &ctrls) != -1);
		if (success) break;

		if (errno != EINTR) throw WzskException(WzskException::V4L2, {{"msg","error setting control parameter " + sref}});
	};
*/

	return success;
};

void JobWzskSrcV4l2::convertYUV420toRGBGrrdInt16(
			unsigned char* src
			, uint16_t* r16
			, uint16_t* g16
			, uint16_t* b16
			, uint16_t* gr16
			, uint16_t* rd16
		) {
	// 484.868ms ; load here is far from ideal (2x 16bit, 2x 8bit)

	// shorthands
	const uint wAcq = xchg->stgwzskframegeo.wAcq;
	const uint hAcq = xchg->stgwzskframegeo.hAcq;

	const uint x0Rgb = xchg->stgwzskframegeo.x0Rgb;
	const uint wRgb = xchg->stgwzskframegeo.wRgb;
	const uint y0Rgb = xchg->stgwzskframegeo.y0Rgb;
	const uint hRgb = xchg->stgwzskframegeo.hRgb;

	const uint x0Grrd = xchg->stgwzskframegeo.x0Grrd;
	const uint wGrrd = xchg->stgwzskframegeo.wGrrd;
	const uint y0Grrd = xchg->stgwzskframegeo.y0Grrd;
	const uint hGrrd = xchg->stgwzskframegeo.hGrrd;
	//

	register int16_t y1, y2, y, u, v;
	register int16_t r, g, b, d;

	unsigned int ldix0, ldix1;
	unsigned int stix;

	// -- YUV420 to RGB (slightly optimized)
	for (unsigned int i = 0; i < hAcq; i += 2) {
		if (i < 2 * y0Rgb) continue;
		if (i >= 2 * (y0Rgb + hRgb)) continue;

		for (unsigned int j = 0; j < wAcq; j += 2) {
			if (j < 2 * x0Rgb) continue;
			if (j >= 2 * (x0Rgb + wRgb)) continue;

			// y load
			ldix0 = i * wAcq + j; // load index (row 0)
			ldix1 = ((i + 1) * wAcq + j);

			y1 = src[ldix0];
			y2 = src[ldix0+1];

			// add values from subsequent row
			y1 += src[ldix1];
			y2 += src[ldix1+1];

			y = y1 + y2;

			// perform binning
			y >>= 2;

			// u, v load
			ldix0 = wAcq * hAcq + i/2 * wAcq/2 + j/2;
			ldix1 = wAcq * hAcq + wAcq/2 * hAcq/2 + i/2 * wAcq/2 + j/2;

			u = src[ldix0];
			v = src[ldix1];

			// - from here, same as convertYUV422toRGBGrrdInt16 (rd has been modified in the meantime)

			// - RGB
			stix = (i/2 - y0Rgb) * wRgb + (j/2 - x0Rgb); // RGB store index

			v -= 128;
			u -= 128;

			// red
			r = v + (v >> 2) + (v >> 3) + (v >> 5);

			if (r + y < 0) d = 0;
			else if (r + y > 255) d = 255;
			else d = r + y; // actual r

			r16[stix] = d;

			// green
			g = (u >> 2) + (u >> 4) + (u >> 5) + (v >> 1) + (v >> 3) + (v >> 4) + (v >> 5);
			if (y - g < 0) d = 0;
			else if (y - g > 255) d = 255;
			else d = y - g; // actual g

			g16[stix] = d;

			// blue
			b = u + (u >> 1) + (u >> 2) + (u >> 6);

			if (b + y < 0) d = 0;
			else if (b + y > 255) d = 255;
			else d = b + y; // actual b

			b16[stix] = d;

			// - Grrd
			if (i < y0Grrd) continue;
			if (i >= y0Grrd + 2 * hGrrd) continue;

			if (j < x0Grrd) continue;
			if (j >= x0Grrd + 2 * wGrrd) continue;

			stix = ((i - y0Grrd) / 2) * wGrrd + (j - x0Grrd) / 2; // Grrd store index

			// gray
			gr16[stix] = y;

			// red dominance 2*r - g - b, iff r >= g and r >= b ; doesn't take into account clamping to [0;255]
			if (r >= -g) {
				if (r >= b) {
					d = (r << 1) + g - b;
					if (d < 0) d = 255;
					else if (d > 255) d = 255;
				} else d = 0;
			} else d = 0;
			rd16[stix] = d;

			// ... is equivalent to
			// (v << 1) + (v >> 1) + (v >> 2) + (v >> 4)
			// - (u >> 2) - (u >> 4) - (u >> 5) - (v >> 1) - (v >> 3) - (v >> 4) - (v >> 5)
			// + u + (u >> 1) + (u >> 2) + (u >> 6)
			// = (v << 1) + (v >> 2) - (v >> 3) - (v >> 5) + u + (u >> 1) - (u >> 4) - (u >> 5) + (u >> 6)
			//d = (v << 1) + (v >> 2) - (v >> 3) - (v >> 5) + u + (u >> 1) - (u >> 4) - (u >> 5) + (u >> 6);
			//if (d < 0) d = 0;
			//else if (d > 255) d = 255;
			//rd16[stix] = d;
		};
	};
};

void JobWzskSrcV4l2::convertYUV420toRGBGrrdNEON(
			unsigned char* src
			, uint16_t* r16
			, uint16_t* g16
			, uint16_t* b16
			, uint16_t* gr16
			, uint16_t* rd16
		) {
#ifdef __arm__
	// 132.437ms ; speed-up of 3.25 as compared to convertYUV422toRGBGrrdInt16

	// YUV420 load strategy:

	// y: 2x 8bytes per row, two rows

	// row i:     d = YY YY YY YY YY YY YY YY
	//       yr0sum =  Y  Y  Y  Y  Y  Y  Y  Y

	// row i+1:   d = YY YY YY YY YY YY YY YY
	//       yr1sum =  Y  Y  Y  Y  Y  Y  Y  Y

	//            y =  Y  Y  Y  Y  Y  Y  Y  Y (= yr0sum + yr1sum)

	// shorthands
	const uint wAcq = xchg->stgwzskframegeo.wAcq;
	const uint hAcq = xchg->stgwzskframegeo.hAcq;

	const uint x0Rgb = xchg->stgwzskframegeo.x0Rgb;
	const uint wRgb = xchg->stgwzskframegeo.wRgb;
	const uint y0Rgb = xchg->stgwzskframegeo.y0Rgb;
	const uint hRgb = xchg->stgwzskframegeo.hRgb;

	const uint x0Grrd = xchg->stgwzskframegeo.x0Grrd;
	const uint wGrrd = xchg->stgwzskframegeo.wGrrd;
	const uint y0Grrd = xchg->stgwzskframegeo.y0Grrd;
	const uint hGrrd = xchg->stgwzskframegeo.hGrrd;
	//

	uint8x16_t d;
	uint16x8_t yr0sum, yr1sum;
	int16x8_t y;

	uint8x8_t e, f;
	int16x8_t k;
	int16x8_t u, v;
	int16x8_t r, g, b, rd;

	const uint8_t zero8 = 0;
	const int16_t zero16 = 0;
	const int16_t onetwoeight16 = 128;
	const int16_t twofivefive16 = 255;

	unsigned int ldix0, ldix1;
	unsigned int stix;

	for (unsigned int i = 0; i < hAcq; i += 2) {
		if (i < 2 * y0Rgb) continue;
		if (i >= 2 * (y0Rgb + hRgb)) continue;

		for (unsigned int j = 0; j < wAcq; j += 8) {
			if (j < 2 * x0Rgb) continue;
			if (j >= 2 * (x0Rgb + wRgb)) continue;

			// - y load and binning
			ldix0 = i * wAcq + j; // load index (row 0)
			ldix1 = (i + 1) * wAcq + j;

			d = vld1q_u8(&(src[ldix0]));
			yr0sum = vpaddlq_u8(d);

			d = vld1q_u8(&(src[ldix1]));
			yr1sum = vpaddlq_u8(d);

			y = vaddq_s16(vreinterpretq_s16_u16(yr0sum), vreinterpretq_s16_u16(yr1sum));
			y = vshrq_n_s16(y, 2);

			// - u, v load and preparation
			ldix0 = wAcq * hAcq + i/2 * wAcq/2 + j/2;
			ldix1 = wAcq * hAcq + wAcq/2 * hAcq/2 + i/2 * wAcq/2 + j/2;

			f = vld1_dup_u8(&zero8);
			k = vld1q_dup_s16(&onetwoeight16);

			e = vld1_u8(&(src[ldix0]));
			u = vreinterpretq_s16_u16(vaddl_u8(e, f));
			u = vsubq_s16(u, k);

			e = vld1_u8(&(src[ldix1]));
			v = vreinterpretq_s16_u16(vaddl_u8(e, f));
			v = vsubq_s16(v, k);
			
			// - RGB (TBD: floating point version)
			stix = (i/2 - y0Rgb) * wRgb + (j/2 - x0Rgb); // RGB store index

			r = vaddq_s16(y, v);
			b = vaddq_s16(y, u);
			
			// (u >> 1), (v >> 1)
			u = vshrq_n_s16(u, 1);
			v = vshrq_n_s16(v, 1);

			g = vsubq_s16(y, v);
			b = vaddq_s16(b, u);

			// (u >> 2), (v >> 2)
			u = vshrq_n_s16(u, 1);
			v = vshrq_n_s16(v, 1);

			r = vaddq_s16(r, v);
			g = vsubq_s16(g, u);
			b = vaddq_s16(b, u);

			// (u >> 4), (v >> 3)
			u = vshrq_n_s16(u, 2);
			v = vshrq_n_s16(v, 1);

			r = vaddq_s16(r, v);
			g = vsubq_s16(g, u);
			g = vsubq_s16(g, v);

			// (u >> 5), (v >> 4)
			u = vshrq_n_s16(u, 1);
			v = vshrq_n_s16(v, 1);

			r = vaddq_s16(r, v);
			g = vsubq_s16(g, u);
			g = vsubq_s16(g, v);

			// (u >> 6), (v >> 5)
			u = vshrq_n_s16(u, 1);
			v = vshrq_n_s16(v, 1);

			g = vsubq_s16(g, v);
			b = vaddq_s16(b, u);

			k = vld1q_dup_s16(&zero16); // >= 0 clamp

			r = vandq_s16(vreinterpretq_s16_u16(vcltq_s16(k, r)), r);
			g = vandq_s16(vreinterpretq_s16_u16(vcltq_s16(k, g)), g);
			b = vandq_s16(vreinterpretq_s16_u16(vcltq_s16(k, b)), b);

			k = vld1q_dup_s16(&twofivefive16); // <= 255 clamp

			r = vandq_s16(vorrq_s16(vreinterpretq_s16_u16(vcgtq_s16(r, k)), r), k);
			g = vandq_s16(vorrq_s16(vreinterpretq_s16_u16(vcgtq_s16(g, k)), g), k);
			b = vandq_s16(vorrq_s16(vreinterpretq_s16_u16(vcgtq_s16(b, k)), b), k);

			vst1q_s16((int16_t*) &(r16[stix]), r);
			vst1q_s16((int16_t*) &(g16[stix]), g);
			vst1q_s16((int16_t*) &(b16[stix]), b);

			// - Grrd
			if (i < y0Grrd) continue;
			if (i >= y0Grrd + 2 * hGrrd) continue;

			if (j < x0Grrd) continue;
			if (j >= x0Grrd + 2 * wGrrd) continue;

			stix = ((i - y0Grrd) / 2) * wGrrd + (j - x0Grrd) / 2; // Grrd store index

			// gray
			vst1q_s16((int16_t*) &(gr16[stix]), y);

			// red dominance r
/*
			rd = r;
*/

/*
			// red dominance r if (r > g and r > b), or 255 on y saturation
			rd = r;
		
			k = vreinterpretq_s16_u16(vandq_u16(vcgtq_s16(r, g), vcgtq_s16(r, b)));
			rd = vandq_s16(rd, k);

			k = vld1q_dup_s16(&twofivefive16);
			rd = vandq_s16(vorrq_s16(rd, vreinterpretq_s16_u16(vceqq_s16(y, k))), k);
*/

			// red dominance 2*r - g - b, iff r >= g and r >= b
			rd = vshlq_n_s16(r, 1);
			rd = vsubq_s16(rd, g);
			rd = vsubq_s16(rd, b);

			k = vreinterpretq_s16_u16(vandq_u16(vcgtq_s16(r, g), vcgtq_s16(r, b)));
			rd = vandq_s16(rd, k);

			k = vld1q_dup_s16(&twofivefive16); // <= 255 clamp

			rd = vandq_s16(vorrq_s16(vreinterpretq_s16_u16(vcgtq_s16(rd, k)), rd), k);

			vst1q_s16((int16_t*) &(rd16[stix]), rd);
		};
	};
#elif __x86_64__
#endif
};

void JobWzskSrcV4l2::convertYUV422toRGBGrrdInt8(
			unsigned char* src
			, uint8_t* r8
			, uint8_t* g8
			, uint8_t* b8
			, uint8_t* gr8
			, uint8_t* rd8
		) {
	// shorthands
	const uint wAcq = xchg->stgwzskframegeo.wAcq;
	const uint hAcq = xchg->stgwzskframegeo.hAcq;

	const uint x0Rgb = xchg->stgwzskframegeo.x0Rgb;
	const uint wRgb = xchg->stgwzskframegeo.wRgb;
	const uint y0Rgb = xchg->stgwzskframegeo.y0Rgb;
	const uint hRgb = xchg->stgwzskframegeo.hRgb;

	const uint x0Grrd = xchg->stgwzskframegeo.x0Grrd;
	const uint wGrrd = xchg->stgwzskframegeo.wGrrd;
	const uint y0Grrd = xchg->stgwzskframegeo.y0Grrd;
	const uint hGrrd = xchg->stgwzskframegeo.hGrrd;
	//

	register int16_t y1, y2, y, u, v; // Y'UV422 integer version
	register int16_t d, e, rd;

	//register float y1, u, y2, v, d; // Y'UV422 floating point version

	unsigned int ldix0, ldix1;
	unsigned int stix;

	// -- YUV422 to RGB (raw versions without initial crop & bin)
/*
	// Y'UV422 integer version (non-optimized)
	for (unsigned int i=0;i<h;i++) {
		for (unsigned int j=0;j<(wAcq/2);j++) {
			ix = 2* (i*wAcq+j*2);
			ix2 = i*wAcq+j*2;

			y1 = src[ix];
			u = src[ix+1];
			y2 = src[ix+2];
			v = src[ix+3];

			v -= 128;
			u -= 128;

			d = y1 + v + (v >> 2) + (v >> 3) + (v >> 5); if (d < 0) d = 0; if (d > 255) d = 255;
			r[ix2] = d;
			d = y1 - ((u >> 2) + (u >> 4) + (u >> 5)) - ((v >> 1) + (v >> 3) + (v >> 4) + (v >> 5)); if (d < 0) d = 0; if (d > 255) d = 255;
			g[ix2] = d;
			d = y1 + u + (u >> 1) + (u >> 2) + (u >> 6); if (d < 0) d = 0; if (d > 255) d = 255;
			b[ix2] = d;

			d = y2 + v + (v >> 2) + (v >> 3) + (v >> 5); if (d < 0) d = 0; if (d > 255) d = 255;
			r[ix2+1] = d;
			d = y2 - ((u >> 2) + (u >> 4) + (u >> 5)) - ((v >> 1) + (v >> 3) + (v >> 4) + (v >> 5)); if (d < 0) d = 0; if (d > 255) d = 255;
			g[ix2+1] = d;
			d = y2 + u + (u >> 1) + (u >> 2) + (u >> 6); if (d < 0) d = 0; if (d > 255) d = 255;
			b[ix2+1] = d;
		};
	};
*/

/*
	// Y'UV422 integer version (slightly optimized)
	for (unsigned int i = 0; i < hAcq; i++) {
		for (unsigned int j = 0; j < wAcq/2; j++) {
			ix2 = i * wAcq + j * 2;
			ix = 2 * ix2;

			// 32bit load
			y1 = src[ix];
			u = src[ix+1];
			y2 = src[ix+2];
			v = src[ix+3];

			v -= 128;
			u -= 128;

			// red
			d = y1 + v + (v >> 2) + (v >> 3) + (v >> 5);
			if (d < 0) e = 0;
			else if (d > 255) e = 255;
			else e = d;
			r[ix2] = e;
			rd0 = 2 * e;

			d = d - y1 + y2;
			if (d < 0) d = 0;
			else if (d > 255) d = 255;
			r[ix2+1] = d;
			rd1 = 2 * d;

			// green
			d = y1 - ((u >> 2) + (u >> 4) + (u >> 5)) - ((v >> 1) + (v >> 3) + (v >> 4) + (v >> 5));
			if (d < 0) e = 0;
			else if (d > 255) e = 255;
			else e = d;
			g[ix2] = e;
			if (rd0 > e) rd0 -= e;
			else rd0 = 0;

			d = d - y1 + y2;
			if (d < 0) d = 0;
			else if (d > 255) d = 255;
			g[ix2+1] = d;
			if (rd1 > d) rd1 -= d;
			else rd1 = 0;

			// blue
			d = y1 + u + (u >> 1) + (u >> 2) + (u >> 6);
			if (d < 0) e = 0;
			else if (d > 255) e = 255;
			else e = d;
			b[ix2] = e;
			if (rd0 > e) rd0 -= e;
			else rd0 = 0;

			d = d - y1 + y2;
			if (d < 0) d = 0;
			else if (d > 255) d = 255;
			b[ix2+1] = d;
			if (rd1 > d) rd1 -= d;
			else rd1 = 0;

			// gray
			gr[ix2] = y1;
			gr[ix2+1] = y2;

			// red dominance min(0, (r-g) + (r-b))
			rd[ix2] = rd0;
			rd[ix2+1] = rd1;
		};
	};
*/

/*
	// Y'UV422 integer version (first optimization attempt)
	ix = 0; // this loop method is slightly slower for some reason
	ix2 = 0;

	do {
	//for (unsigned int i = 0; i < hAcq; i++) {
	//	for (unsigned int j = 0; j < wAcq; j += 2) {
			// ix2 = i * wAcq + j;
			// ix = 2 * ix2;

			// non-standard order
			y1 = src[ix];
			y2 = src[ix+2];

			u = src[ix+1] - 128; // this is a significant slow-down as compared to loading all in a row and doing -= afterwards!
			v = src[ix+3] - 128;

			// red
			d = y1 + v + (v >> 2) + (v >> 3) + (v >> 5);
			if (d < 0) r[ix2] = 0; // conditional store is slow as well
			else if (d > 255) r[ix2] = 255;
			else r[ix2] = d;

			d = d - y1 + y2;
			if (d < 0) r[ix2+1] = 0;
			else if (d > 255) r[ix2+1] = 255;
			else r[ix2+1] = d;

			// green
			d = y1 - ((u >> 2) + (u >> 4) + (u >> 5)) - ((v >> 1) + (v >> 3) + (v >> 4) + (v >> 5));
			if (d < 0) g[ix2] = 0;
			else if (d > 255) g[ix2] = 255;
			else g[ix2] = d;

			d = d - y1 + y2;
			if (d < 0) g[ix2+1] = 0;
			else if (d > 255) g[ix2+1] = 255;
			else g[ix2+1] = d;

			// blue
			d = y1 + u + (u >> 1) + (u >> 2) + (u >> 6);
			if (d < 0) b[ix2] = 0;
			else if (d > 255) b[ix2] = 255;
			else b[ix2] = d;

			d = d - y1 + y2;
			if (d < 0) b[ix2+1] = 0;
			else if (d > 255) b[ix2+1] = 255;
			else b[ix2+1] = d;

			ix += 4;
			ix2 += 2;
	//	};
	//};
	} while (ix2 < whAcq);
*/
/*
	// Y'UV422 floating point version (non-optimized)
	for (unsigned int i = 0; i < hAcq; i++) {
		for (unsigned int j = 0; j < wAcq/2; j++) {
			ix = 2 * (i * wAcq + j * 2);
			ix2 = i * wAcq + j * 2;

			// non-standard order
			y1 = src[ix];
			u = src[ix+1];
			y2 = src[ix+2];
			v = src[ix+3];

			d = y1 + 1.402*(v-128.0); if (d < 0.0) d = 0.0; if (d > 255.0) d = 255.0;
			r[ix2] = lround(d);
			d = y1 - 0.344*(u-128.0) - 0.714*(v-128.0); if (d < 0.0) d = 0.0; if (d > 255.0) d = 255.0;
			g[ix2] = lround(d);
			d = y1 + 1.772*(u-128.0); if (d < 0.0) d = 0.0; if (d > 255.0) d = 255.0;
			b[ix2] = lround(d);

			d = y2 + 1.402*(v-128.0); if (d < 0.0) d = 0.0; if (d > 255.0) d = 255.0;
			r[ix2+1] = lround(d);
			d = y2 - 0.344*(u-128.0) - 0.714*(v-128.0); if (d < 0.0) d = 0.0; if (d > 255.0) d = 255.0;
			g[ix2+1] = lround(d);
			d = y2 + 1.772*(u-128.0); if (d < 0.0) d = 0.0; if (d > 255.0) d = 255.0;
			b[ix2+1] = lround(d);
		};
	};
*/
/*
	// Y'UV422 floating point version (slightly optimized)
	ix = 0;
	ix2 = 0;

	do {
	//for (unsigned int i = 0; i < hAcq; i++) {
	//	for (unsigned int j = 0; j < wAcq/2; j++) {
			//ix = 2 * (i * wAcq + j * 2);
			//ix2 = i * wAcq + j * 2;

			// non-standard order
			y1 = src[ix];
			y2 = src[ix+2];

			u = src[ix+1] - 128.0;
			v = src[ix+3] - 128.0;

			// red
			d = y1 + 1.402*v;
			if (d < 0.0) r[ix2] = 0;
			else if (d > 255.0) r[ix2] = 255;
			else r[ix2] = lround(d);

			d = d - y1 + y2;
			if (d < 0.0) r[ix2+1] = 0;
			else if (d > 255.0) r[ix2+1] = 255;
			else r[ix2+1] = lround(d);

			// green
			d = y1 - 0.344*u - 0.714*v;
			if (d < 0.0) g[ix2] = 0;
			else if (d > 255.0) g[ix2] = 255;
			else g[ix2] = lround(d);

			d = d - y1 + y2;
			if (d < 0.0) g[ix2+1] = 0;
			else if (d > 255.0) g[ix2+1] = 255;
			else g[ix2+1] = lround(d);

			// blue
			d = y1 + 1.772*u;
			if (d < 0.0) b[ix2] = 0;
			else if (d > 255.0) b[ix2] = 255;
			else b[ix2] = lround(d);

			d = d - y1 + y2;
			if (d < 0.0) b[ix2+1] = 0;
			else if (d > 255.0) b[ix2+1] = 255;
			else b[ix2+1] = lround(d);

			ix += 4;
			ix2 += 2;
	//	};
	//};
	} while (ix2 < whAcq);
*/

	// -- YUV422 to RGB (slightly optimized)
	for (unsigned int i = 0; i < hAcq; i += 2) {
		if (i < 2 * y0Rgb) continue;
		if (i >= 2 * (y0Rgb + hRgb)) continue;

		for (unsigned int j = 0; j < 2 * wAcq; j += 4) {
			if (j < 4 * x0Rgb) continue;
			if (j >= 4 * (x0Rgb + wRgb)) continue;

			ldix0 = (i * 2 * wAcq + j); // load index (row 0)
			ldix1 = ((i + 1) * 2 * wAcq + j);

			// 32bit load (fast)
			y1 = src[ldix0];
			u = src[ldix0+1];
			y2 = src[ldix0+2];
			v = src[ldix0+3];

			// add values from subsequent row (potentially slow)
			y1 += src[ldix1];
			u += src[ldix1+1];
			y2 += src[ldix1+2];
			v += src[ldix1+3];

			y = y1 + y2;

			// perform binning
			y >>= 2;

			u >>= 1;
			v >>= 1;

			// - RGB
			stix = (i/2 - y0Rgb) * wRgb + (j/4 - x0Rgb); // RGB store index

			v -= 128;
			u -= 128;

			// red
			d = y + v + (v >> 2) + (v >> 3) + (v >> 5);
			if (d < 0) e = 0;
			else if (d > 255) e = 255;
			else e = d;
			r8[stix] = e;
			rd = 2 * e;

			// green
			d = y - ((u >> 2) + (u >> 4) + (u >> 5)) - ((v >> 1) + (v >> 3) + (v >> 4) + (v >> 5));
			if (d < 0) e = 0;
			else if (d > 255) e = 255;
			else e = d;
			g8[stix] = e;
			if (rd > e) rd -= e;
			else rd = 0;

			// blue
			d = y + u + (u >> 1) + (u >> 2) + (u >> 6);
			if (d < 0) e = 0;
			else if (d > 255) e = 255;
			else e = d;
			b8[stix] = e;
			if (rd > e) rd -= e;
			else rd = 0;

			// - Grrd
			if (i < 2 * y0Grrd) continue;
			if (i >= 2 * (y0Grrd + hGrrd)) continue;

			if (j < 4 * x0Rgb) continue;
			if (j >= 4 * (x0Rgb + wGrrd)) continue;

			stix = (i/2 - y0Grrd) * wGrrd + (j/4 - x0Grrd); // Grrd store index

			// gray
			gr8[stix] = y;

			// red dominance min(0, (r-g) + (r-b))
			rd8[stix] = rd;
		};
	};
};

void JobWzskSrcV4l2::convertYUV422toRGBGrrdInt16(
			unsigned char* src
			, uint16_t* r16
			, uint16_t* g16
			, uint16_t* b16
			, uint16_t* gr16
			, uint16_t* rd16
		) {
	// 432.092ms

	// shorthands
	const uint wAcq = xchg->stgwzskframegeo.wAcq;
	const uint hAcq = xchg->stgwzskframegeo.hAcq;

	const uint x0Rgb = xchg->stgwzskframegeo.x0Rgb;
	const uint wRgb = xchg->stgwzskframegeo.wRgb;
	const uint y0Rgb = xchg->stgwzskframegeo.y0Rgb;
	const uint hRgb = xchg->stgwzskframegeo.hRgb;

	const uint x0Grrd = xchg->stgwzskframegeo.x0Grrd;
	const uint wGrrd = xchg->stgwzskframegeo.wGrrd;
	const uint y0Grrd = xchg->stgwzskframegeo.y0Grrd;
	const uint hGrrd = xchg->stgwzskframegeo.hGrrd;
	//

	register int16_t y1, y2, y, u, v; // Y'UV422 integer version
	register int16_t r, g, b, rd;

	unsigned int ldix0, ldix1;
	unsigned int stix;

	// -- YUV422 to RGB (slightly optimized)
	for (unsigned int i = 0; i < hAcq; i += 2) {
		if (i < 2 * y0Rgb) continue;
		if (i >= 2 * (y0Rgb + hRgb)) continue;

		for (unsigned int j = 0; j < 2 * wAcq; j += 4) {
			if (j < 4 * x0Rgb) continue;
			if (j >= 4 * (x0Rgb + wRgb)) continue;

			ldix0 = (i * 2 * wAcq + j); // load index (row 0)
			ldix1 = ((i + 1) * 2 * wAcq + j);

			// 32bit load (fast)
			y1 = src[ldix0];
			u = src[ldix0+1];
			y2 = src[ldix0+2];
			v = src[ldix0+3];

			// add values from subsequent row (potentially slow)
			y1 += src[ldix1];
			u += src[ldix1+1];
			y2 += src[ldix1+2];
			v += src[ldix1+3];

			y = y1 + y2;

			// perform binning
			y >>= 2;

			u >>= 1;
			v >>= 1;

			// - RGB
			stix = (i/2 - y0Rgb) * wRgb + (j/4 - x0Rgb); // RGB store index

			v -= 128;
			u -= 128;

			// red
			r = v + (v >> 2) + (v >> 3) + (v >> 5);

			if (r + y < 0) r = 0;
			else if (r + y > 255) r = 255;
			else r = r + y;

			r16[stix] = r;

			// green
			g = (u >> 2) + (u >> 4) + (u >> 5) + (v >> 1) + (v >> 3) + (v >> 4) + (v >> 5);
			if (y - g < 0) g = 0;
			else if (y - g > 255) g = 255;
			else g = y - g;

			g16[stix] = g;

			// blue
			b = u + (u >> 1) + (u >> 2) + (u >> 6);

			if (b + y < 0) b = 0;
			else if (b + y > 255) b = 255;
			else b = b + y;

			b16[stix] = b;

			// - Grrd
			if (i < 2 * y0Grrd) continue;
			if (i >= 2 * (y0Grrd + hGrrd)) continue;

			if (j < 4 * x0Rgb) continue;
			if (j >= 4 * (x0Rgb + wGrrd)) continue;

			stix = (i/2 - y0Grrd) * wGrrd + (j/4 - x0Grrd); // Grrd store index

			// gray
			gr16[stix] = y;

			// red dominance 2*r - g - b, iff r >= g and r >= b
			if (y == 255) rd = 255; // saturated pixels as well
			else {
				rd = 0;
				if (r > g)
					if (r > b) {
						rd = (r << 1) - g - b;
						if (rd > 255) rd = 255;
					};
			};
			rd16[stix] = rd;

			// ... is equivalent to
			// (v << 1) + (v >> 1) + (v >> 2) + (v >> 4)
			// - (u >> 2) - (u >> 4) - (u >> 5) - (v >> 1) - (v >> 3) - (v >> 4) - (v >> 5)
			// + u + (u >> 1) + (u >> 2) + (u >> 6)
			// = (v << 1) + (v >> 2) - (v >> 3) - (v >> 5) + u + (u >> 1) - (u >> 4) - (u >> 5) + (u >> 6)
			//d = (v << 1) + (v >> 2) - (v >> 3) - (v >> 5) + u + (u >> 1) - (u >> 4) - (u >> 5) + (u >> 6);
			//if (d < 0) d = 0;
			//else if (d > 255) d = 255;
			//rd16[stix] = d;
		};
	};
};

bool JobWzskSrcV4l2::setExposure(
			const bool autoNotManual
			, const float _Texp // in s
		) {
	bool success = false;

	// conversion to OV5640 scale same as in JobWzskSrcFpga::camif_setExp()
	usmallint Texp;
	
	float Texp_imd = 16.0 * _Texp / (2844.0/25e6); // units of line*16, one line takes (2844/25e6)s = 113.76µs at pclk = 25MHz

	if (Texp_imd < 1.0) Texp = 1;
	else if (Texp_imd > 65535.0) Texp = 65535;
	else Texp = lround(Texp_imd);

	try {
		if (!autoNotManual) {
			success = setCtrl(V4L2_CID_EXPOSURE_AUTO, "auto exposure type", false, V4L2_EXPOSURE_MANUAL, false);
			if (success) success = setCtrl(V4L2_CID_EXPOSURE_ABSOLUTE, "exposure time absolute", false, Texp, false);

		} else {
			success = setCtrl(V4L2_CID_EXPOSURE_AUTO, "auto exposure type", false, V4L2_EXPOSURE_AUTO, false);
		};

	} catch (WzskException& e) {
		cout << e.getSquawk(VecWzskVError::getIx, VecWzskVError::getTitle, VecWzskVLocale::ENUS) << endl;
	};

	return success;
};

bool JobWzskSrcV4l2::setFocus(
			const float _focus // 0 .. 1
		) {
	bool success = false;

	// conversion to OV5640 scale same as in JobWzskSrcFpga::camif_setFocus()
	usmallint focus;
	
	if (_focus < 0.0) focus = 0;
	else if (_focus > 1.0) focus = 1023;
	else focus = lround(1023.0 * _focus);

	try {
		success = setCtrl(V4L2_CID_FOCUS_ABSOLUTE, "focus absolute", false, focus, false);

	} catch (WzskException& e) {
		cout << e.getSquawk(VecWzskVError::getIx, VecWzskVError::getTitle, VecWzskVLocale::ENUS) << endl;
	};

	return success;
};
// IP cust --- IEND

// IP spec --- INSERT

void JobWzskSrcV4l2::handleRequest(
			DbsWzsk* dbswzsk
			, ReqWzsk* req
		) {
	if (req->ixVBasetype == ReqWzsk::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\ttest" << endl;
		} else if (req->cmd == "test") {
			req->retain = handleTest(dbswzsk);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::TIMER) {
		if (ixVSge == VecVSge::CNVIDLE) handleTimerInSgeCnvidle(dbswzsk, req->sref);
	};
};

bool JobWzskSrcV4l2::handleTest(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleTest --- IBEGIN
	timespec deltat;

	unlockAccess("handleTest");

	cout << "\ttesting manual exposure ..." << endl;

	deltat = {.tv_sec = 0, .tv_nsec = 500000000}; // 500ms

	setCtrl(V4L2_CID_EXPOSURE_AUTO, "auto exposure type", false, V4L2_EXPOSURE_MANUAL, false);

	for (int val = 1; val < 65535; val *= 2) {
		setCtrl(V4L2_CID_EXPOSURE_ABSOLUTE, "exposure time absolute (1 .. 65535)", false, val, false);
		nanosleep(&deltat, NULL);
	};

	setCtrl(V4L2_CID_EXPOSURE_AUTO, "auto exposure type", false, V4L2_EXPOSURE_AUTO, false);

	deltat = {.tv_sec = 3, .tv_nsec = 0};
	nanosleep(&deltat, NULL);

	cout << "\ttesting manual focus ..." << endl;

	deltat = {.tv_sec = 0, .tv_nsec = 100000000}; // 100ms

	for (int val = 0; val < 1023; val += 10) {
		setCtrl(V4L2_CID_FOCUS_ABSOLUTE, "focus absolute (0 .. 1023)", false, val, false);
		nanosleep(&deltat, NULL);
	};

	for (int val = 1020; val > 0; val -= 10) {
		setCtrl(V4L2_CID_FOCUS_ABSOLUTE, "focus absolute (0 .. 1023)", false, val, false);
		nanosleep(&deltat, NULL);
	};

	cout << "\texposure / focus test completed." << endl;

	lockAccess("handleTest");

	// IP handleTest --- IEND
	return retval;
};

void JobWzskSrcV4l2::handleTimerInSgeCnvidle(
			DbsWzsk* dbswzsk
			, const string& sref
		) {
	changeStage(dbswzsk, nextIxVSgeSuccess);
};

void JobWzskSrcV4l2::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if ((call->ixVCall == VecWzskVCall::CALLWZSKCALLBACK) && (call->jref == jref)) {
		call->abort = handleCallWzskCallbackFromSelf(dbswzsk, call->argInv.ix, call->argInv.sref);
	};
};

bool JobWzskSrcV4l2::handleCallWzskCallbackFromSelf(
			DbsWzsk* dbswzsk
			, const uint ixInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallWzskCallbackFromSelf --- IBEGIN
	if (trylockAccess("handleCallWzskCallbackFromSelf")) {
		if (srefInv == "") {
			if (ixVSge == VecVSge::READY) changeStage(dbswzsk, VecVSge::IDLE);
			else nextIxVSgeFailure = VecVSge::IDLE;

		} else if (srefInv == "acq") {
			if (ixVSge == VecVSge::READY) {
				ixRi = ixInv;
				shrdat.resultAcq.lock(jref, ixInv);

				changeStage(dbswzsk, VecVSge::CNVIDLE);

			} else {
				cout << "discarded frame at index " << ixInv << endl;

				shrdat.resultAcq.unlock(jref, ixInv); // put result item back in queue
			};
		};

		unlockAccess("handleCallWzskCallbackFromSelf");

	} else {
		if (srefInv == "acq") shrdat.resultAcq.unlock(jref, ixInv); // put result item back in queue
	};
	// IP handleCallWzskCallbackFromSelf --- IEND
	return retval;
};

void JobWzskSrcV4l2::changeStage(
			DbsWzsk* dbswzsk
			, uint _ixVSge
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswzsk); break;
				case VecVSge::READY: leaveSgeReady(dbswzsk); break;
				case VecVSge::CNVIDLE: leaveSgeCnvidle(dbswzsk); break;
				case VecVSge::CONVERT: leaveSgeConvert(dbswzsk); break;
			};

			setStage(dbswzsk, _ixVSge);
			reenter = false;
			// IP changeStage.refresh1 --- INSERT
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswzsk, reenter); break;
			case VecVSge::READY: _ixVSge = enterSgeReady(dbswzsk, reenter); break;
			case VecVSge::CNVIDLE: _ixVSge = enterSgeCnvidle(dbswzsk, reenter); break;
			case VecVSge::CONVERT: _ixVSge = enterSgeConvert(dbswzsk, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string JobWzskSrcV4l2::getSquawk(
			DbsWzsk* dbswzsk
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::IDLE) || (ixVSge == VecVSge::READY) || (ixVSge == VecVSge::CONVERT) ) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			if (ixVSge == VecVSge::IDLE) retval = "idle";
			else if (ixVSge == VecVSge::READY) retval = "ready";
			else if (ixVSge == VecVSge::CONVERT) retval = "converting";
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			if (ixVSge == VecVSge::IDLE) retval = "inaktiv";
			else if (ixVSge == VecVSge::READY) retval = "bereit";
			else if (ixVSge == VecVSge::CONVERT) retval = "Konvertierung";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint JobWzskSrcV4l2::enterSgeIdle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- IBEGIN
	pthread_t oldAcq;

	shrdat.mAcq.lock("JobWzskSrcV4l2", "enterSgeIdle");

	oldAcq = shrdat.acq; // original will be set 0 in the process

	if (oldAcq != 0) {
		shrdat.cancelAcq = true;

		shrdat.mAcq.unlock("JobWzskSrcV4l2", "enterSgeIdle[1]");

		pthread_join(oldAcq, NULL);

	} else shrdat.mAcq.unlock("JobWzskSrcV4l2", "enterSgeIdle[2]");;
	// IP enterSgeIdle --- IEND

	return retval;
};

void JobWzskSrcV4l2::leaveSgeIdle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWzskSrcV4l2::enterSgeReady(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::READY;

	// IP enterSgeReady --- IBEGIN
	int res;
	pthread_attr_t attr;

	if (shrdat.acq == 0) {
		shrdat.mAcq.lock("JobWzskSrcV4l2", "enterSgeReady");

		shrdat.cancelAcq = false;

		pthread_attr_init(&attr);
		pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

		for (unsigned int i = 0; i < 3; i++) {
			res = pthread_create(&shrdat.acq, &attr, &runAcq, (void*) this);
			if ((res == 0) || (res != EAGAIN)) break;
		};
		if (res != 0) cout << "JobWzskSrcV4l2::enterSgeReady() error creating acquisition thread (" << res << ")" << endl;

		shrdat.mAcq.unlock("JobWzskSrcV4l2", "enterSgeReady");

	} else if (nextIxVSgeFailure != VecVSge::READY) {
		// claim run attribute has been retracted
		retval = nextIxVSgeFailure;
	};
	// IP enterSgeReady --- IEND

	return retval;
};

void JobWzskSrcV4l2::leaveSgeReady(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeReady --- INSERT
};

uint JobWzskSrcV4l2::enterSgeCnvidle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::CNVIDLE;
	nextIxVSgeSuccess = VecVSge::CONVERT;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeCnvidle --- INSERT

	return retval;
};

void JobWzskSrcV4l2::leaveSgeCnvidle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeCnvidle --- INSERT
};

uint JobWzskSrcV4l2::enterSgeConvert(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::CONVERT;

	// IP enterSgeConvert --- IBEGIN
	Shrdat::ResultitemAcq* ri = (Shrdat::ResultitemAcq*) shrdat.resultAcq[ixRi];

	if (!stg.YUV422NotYUV420) convertYUV420toRGBGrrdNEON((unsigned char*) ri->buf, ri->r16, ri->g16, ri->b16, ri->gr16, ri->rd16);
	else convertYUV422toRGBGrrdInt16((unsigned char*) ri->buf, ri->r16, ri->g16, ri->b16, ri->gr16, ri->rd16);

	xchg->triggerIxSrefCall(dbswzsk, VecWzskVCall::CALLWZSKRESULTNEW, jref, ixRi, "acq"); // AcqPreview and IprTrace (= super jobs) will lock the result item

	shrdat.resultAcq.unlock(jref, ixRi); // only puts result item back in queue if preceding call doesn't add new locks

	retval = VecVSge::READY;
	// IP enterSgeConvert --- IEND

	return retval;
};

void JobWzskSrcV4l2::leaveSgeConvert(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeConvert --- INSERT
};

bool JobWzskSrcV4l2::handleClaim(
			DbsWzsk* dbswzsk
			, map<ubigint,Sbecore::Claim*>& claims
			, const ubigint jrefNewest
		) {
	bool mod = false;

	// IP handleClaim --- IBEGIN

	// claim policy:
	// - all claims can be fulfilled
	// - change stage to ready if any claim is run (run is continuous)

	Claim* claim = NULL;

	bool run = false;

	// survey
	for (auto it = claims.begin(); it != claims.end(); it++) {
		claim = it->second;

		if (claim->run) {
			run = true;
			break;
		};
	};

	// update fulfilled and taken status
	for (auto it = claims.begin(); it != claims.end(); it++) {
		claim = it->second;

		claim->fulfilled = true;
		claim->takenNotAvailable = false;
	};

	// initiate stage change
	if (!run) {
		nextIxVSgeFailure = VecVSge::IDLE;

	} else {
		nextIxVSgeFailure = VecVSge::READY;
		if (ixVSge == VecVSge::IDLE) changeStage(dbswzsk, VecVSge::READY);
	};

	mod = true; // for simplicity
	// IP handleClaim --- IEND

	return mod;
};
