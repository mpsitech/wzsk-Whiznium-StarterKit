/**
	* \file WzskcmbdAppsrv.cpp
	* application server for Wzsk combined daemon (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "Wzskcmbd.h"

#include "WzskcmbdAppsrv.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WzskcmbdAppsrv
 ******************************************************************************/

MHD_Daemon* WzskcmbdAppsrv::start(
			XchgWzskcmbd* xchg
		) {
	if (xchg->stgwzskappsrv.https) {
		return MHD_start_daemon(MHD_USE_THREAD_PER_CONNECTION | MHD_USE_POLL | MHD_USE_SSL, xchg->stgwzskappsrv.port, &MhdAccept, (void*) xchg, &MhdCallback, (void*) xchg, MHD_OPTION_HTTPS_MEM_KEY, xchg->key.c_str(), MHD_OPTION_HTTPS_MEM_CERT, xchg->cert.c_str(), MHD_OPTION_NOTIFY_COMPLETED, &MhdComplete, (void*) xchg, MHD_OPTION_END);
	} else {
		return MHD_start_daemon(MHD_USE_THREAD_PER_CONNECTION | MHD_USE_POLL, xchg->stgwzskappsrv.port, &MhdAccept, (void*) xchg, &MhdCallback, (void*) xchg, MHD_OPTION_NOTIFY_COMPLETED, &MhdComplete, (void*) xchg, MHD_OPTION_END);
	};
};

void WzskcmbdAppsrv::stop(
			MHD_Daemon* d
		) {
	MHD_stop_daemon(d);
};

int WzskcmbdAppsrv::MhdAccept(
			void* cls
			, const sockaddr* addr
			, socklen_t addrlen
		) {
	return MHD_YES;
};

int WzskcmbdAppsrv::MhdCallback(
			void* cls
			, MHD_Connection* connection
			, const char* url
			, const char* method
			, const char* version
			, const char* upload_data
			, size_t* upload_data_size
			, void** con_cls
		) {
	XchgWzsk* xchg = (XchgWzsk*) cls;

	MHD_Response* response;
	int retval = MHD_YES;

	ReqWzsk* req;
	uint ixVBasetype = ReqWzsk::VecVBasetype::NONE;

	sockaddr* addr;

	string ip;
#ifndef _WIN32
	char ipstr[64];
#endif

	string mimetype;
	size_t ptr;

	uint ixWzskVDpch;

	ubigint jrefNotify;

	DcolWzsk* dcol;

	char empty[] = "\n";
	char invalid[] = "<html><head><title>Invalid request</title></head><body><p>Invalid request!</p></body></html>";

	string s, s2;

	bool valid;

	if (*con_cls == NULL) {
		// new request
		s = string(url);

		if (strcmp(method, "GET") == 0) {
			// cout << "have GET request, url is '" << s << "'" << endl;

			if (s == "/") {
				ixVBasetype = ReqWzsk::VecVBasetype::REDIRECT;

			} else if (s.find("/web/") != string::npos) {
				// cout << "request for '" << s.substr(4) << "' by html transfer" << endl;

				// ex. "/web/CrdWzskNav/CrdWzskNav.html" ; note that eventual parameters such as "?scrJref=abcd1234efgh5678" are not included in url

				// inhibit requests to ../ directories
				if (s.find("../") == string::npos) {

					// check if file exists
					s2 = xchg->stgwzskpath.webpath + s.substr(4);
					if (access(s2.c_str(), R_OK) == 0) {
						ixVBasetype = ReqWzsk::VecVBasetype::WEB;
						// cout << "MhdCallback() HTML request for '" << s2 << "'" << endl;
					};
				};

			} else if (s.find("/notify") != string::npos) {
				// always "/notify/abcd1234efgh5678"
				ixVBasetype = ReqWzsk::VecVBasetype::NOTIFY;

			} else if (s.find("/poll") != string::npos) {
				// always "/poll/abcd1234efgh5678"
				ixVBasetype = ReqWzsk::VecVBasetype::POLL;

			} else if (s.find("/download/") != string::npos) {
				// ex. "/download/abcd1234efgh5678"
				ixVBasetype = ReqWzsk::VecVBasetype::DOWNLOAD;
			};

		} else if (strcmp(method, "POST") == 0) {
			if (s.find("/dpch") != string::npos) {
				// always "/dpch"
				ixVBasetype = ReqWzsk::VecVBasetype::DPCHAPP;

			} else if (s.find("/upload/") != string::npos) {
				// ex. "/upload/abcd1234efgh5678"
				ixVBasetype = ReqWzsk::VecVBasetype::UPLOAD;
			};
		};

		if (ixVBasetype == ReqWzsk::VecVBasetype::NONE) {
			// not a valid request
			response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
			//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
			retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
			MHD_destroy_response(response);

		} else if (ixVBasetype == ReqWzsk::VecVBasetype::REDIRECT) {
			response = MHD_create_response_from_buffer(0, NULL, MHD_RESPMEM_PERSISTENT);
			MHD_add_response_header(response, "Location", "/web/CrdWzskStart/CrdWzskStart.html");
			retval = MHD_queue_response(connection, MHD_HTTP_MOVED_PERMANENTLY, response);
			MHD_destroy_response(response);

		} else {
			addr = MHD_get_connection_info(connection, MHD_CONNECTION_INFO_CLIENT_ADDRESS)->client_addr;

			if (addr->sa_family == AF_INET) {
#ifdef _WIN32
				ip = inet_ntoa(((sockaddr_in*)addr)->sin_addr);
#else
				inet_ntop(AF_INET, &(((sockaddr_in*)addr)->sin_addr), ipstr, 64);
				ip = ipstr;
#endif
			};

			req = new ReqWzsk(ixVBasetype, ReqWzsk::VecVState::RECEIVE, ip);
			*con_cls = req;

			if (req->ixVBasetype == ReqWzsk::VecVBasetype::WEB) {
				// --- open file and initiate transmission
				req->filename = xchg->stgwzskpath.webpath + s.substr(4);

				req->file = new fstream();
				req->file->open(req->filename.c_str(), fstream::in | fstream::binary);

				// get file length
				req->file->seekg(0, ios::end);
				req->filelen = req->file->tellg();
				req->file->seekg(0, ios::beg);

				if (req->filelen == 0) {
					// empty files require special handling
					response = MHD_create_response_from_buffer(strlen(empty), empty, MHD_RESPMEM_PERSISTENT);
					//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
					retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
					MHD_destroy_response(response);

				} else {
					response = MHD_create_response_from_callback(req->filelen, 8*1024, &MhdFilesend, req, NULL);

					// determine MIME type from file extension
					ptr = req->filename.rfind('.');
					if (ptr != string::npos) mimetype = VecWzskVMimetype::getTitle(VecWzskVMimetype::getIx(req->filename.substr(ptr+1)));
					if (mimetype.length() == 0) mimetype = VecWzskVMimetype::getTitle(VecWzskVMimetype::TXT);
					MHD_add_response_header(response, "Content-Type", mimetype.c_str());					

					//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
					retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
					MHD_destroy_response(response);
				};

			} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::DPCHAPP) {
				// --- prepare POST processor
				req->pp = MHD_create_post_processor(connection, 8*1024, MhdPostrecv, req);

			} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::NOTIFY) {
				// --- notify on dispatch in dispatch collector
				req->jref = Scr::descramble(s.substr(s.find("/notify/")+8));
				valid = (req->jref != 0);

				if (valid) valid = validateIp(xchg, req);

				if (valid) {
					jrefNotify = xchg->getRefPreset(VecWzskVPreset::PREWZSKJREFNOTIFY, req->jref);

					dcol = xchg->getDcolByJref(req->jref);
					if (!dcol) {
						dcol = xchg->addDcol(req->jref);
						if (dcol) jrefNotify = req->jref;
					};

					valid = dcol;
				};

				if (valid) {
					req->ixWzskVLocale = dcol->ixWzskVLocale;

					if (dcol->dpchs.empty()) {
						if (dcol->hot) {
							// send default reply immediately
							req->dpcheng = new DpchEngWzskAck(req->jref);

							dcol->hot = false;
							dcol->unlockAccess("WzskcmbdAppsrv", "MhdCallback[1]");

						} else if (jrefNotify != dcol->jref) {
							// ask client to resort to POLL mode
							req->dpcheng = new DpchEngWzskSuspend(req->jref);

							dcol->unlockAccess("WzskcmbdAppsrv", "MhdCallback[2]");

						} else {
							// wait for next notification to arrive in dispatch collector
							
							// default req->dpcheng to be overwritten
							req->dpcheng = new DpchEngWzskAck(req->jref);
							dcol->req = req;

							// note: when dcol with req != NULL is deleted, req->cReady will be broadcast
							req->cReady.lockMutex("WzskcmbdAppsrv", "MhdCallback[1]");
							dcol->unlockAccess("WzskcmbdAppsrv", "MhdCallback[3]");
							req->cReady.timedwait(15000000, "WzskcmbdAppsrv", "MhdCallback");
							// cout << "got one after timedwait" << endl;
							req->cReady.unlockMutex("WzskcmbdAppsrv", "MhdCallback[1]");

							dcol = xchg->getDcolByJref(req->jref);
							if (dcol) {
								// note: the destructor of dcol is called after dcol is removed from the list from which it can be found by getDcolByJref()
								dcol->req = NULL;
								dcol->unlockAccess("WzskcmbdAppsrv", "MhdCallback[4]");

							} else {
								delete req->dpcheng;
								req->dpcheng = new DpchEngWzskConfirm(false, req->jref);
							};
						};

						writeDpchEng(xchg, req);
						req->ixVState = ReqWzsk::VecVState::REPLY;

						// send reply ; note that the result of timedwait() doesn't matter
						response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);

					} else {
						req->dpcheng = xchg->pullFirstDpch(dcol);
						// cout << "pulled one" << endl;

						dcol->hot = true;
						dcol->unlockAccess("WzskcmbdAppsrv", "MhdCallback[5]");

						writeDpchEng(xchg, req);
						req->ixVState = ReqWzsk::VecVState::REPLY;

						// send first dispatch available in dispatch collector
						response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);
					};
				};

				if (!valid) {
					response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
					retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
					MHD_destroy_response(response);
				};

			} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::POLL) {
				// --- send first dispatch available in dispatch collector
				req->jref = Scr::descramble(s.substr(s.find("/poll/")+6));
				valid = (req->jref != 0);

				if (valid) valid = validateIp(xchg, req);

				if (valid) {
					dcol = xchg->getDcolByJref(req->jref);
					if (!dcol) dcol = xchg->addDcol(req->jref);

					valid = dcol;
				};

				if (valid) {
					req->ixWzskVLocale = dcol->ixWzskVLocale;
					dcol->hot = false;

					if (dcol->dpchs.empty()) {
						// send default reply
						req->dpcheng = new DpchEngWzskAck(req->jref);

					} else {
						req->dpcheng = xchg->pullFirstDpch(dcol);
						// cout << "pulled one" << endl;
					};

					dcol->unlockAccess("WzskcmbdAppsrv", "MhdCallback[6]");

					writeDpchEng(xchg, req);
					req->ixVState = ReqWzsk::VecVState::REPLY;

					// send reply
					response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
					retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
					MHD_destroy_response(response);
				};

				if (!valid) {
					response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
					retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
					MHD_destroy_response(response);
				};

			} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::UPLOAD) {
				req->jref = Scr::descramble(s.substr(s.find("/upload/")+8));

				// generate file in tmp directory, and open it
				req->filename = xchg->stgwzskpath.tmppath + "/" + Tmp::newfile(xchg->stgwzskpath.tmppath, "");

				req->pp = MHD_create_post_processor(connection, 8*1024, MhdPostrecv, req);

			} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::DOWNLOAD) {
				// --- pass request to jobprc, to ask for filename in tmp directory ; then proceed sending - same procedure as for HTML
				req->jref = Scr::descramble(s.substr(s.find("/download/")+10));
				valid = validateIp(xchg, req);

				if (valid) {
					validateJrefNotify(xchg, req);

					xchg->addReq(req);

					// wait for reply
					req->cReady.lockMutex("WzskcmbdAppsrv", "MhdCallback[2]");
					if (req->ixVState != ReqWzsk::VecVState::REPLY) req->cReady.wait("WzskcmbdAppsrv", "MhdCallback[1]");
					req->cReady.unlockMutex("WzskcmbdAppsrv", "MhdCallback[2]");

					// cout << "preparing '" << req->filename << "' for download transfer" << endl;

					valid = (access(req->filename.c_str(), R_OK) == 0);
				};

				if (valid) {
					req->file = new fstream();
					req->file->open(req->filename.c_str(), fstream::in | fstream::binary);

					// get file length
					req->file->seekg(0, ios::end);
					req->filelen = req->file->tellg();
					req->file->seekg(0, ios::beg);

					if (req->filelen == 0) {
						// empty files require special handling
						response = MHD_create_response_from_buffer(strlen(empty), empty, MHD_RESPMEM_PERSISTENT);
						//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);

					} else {
						response = MHD_create_response_from_callback(req->filelen, 8*1024, &MhdFilesend, req, NULL);
						//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);
					};
				};

				if (!valid) {
					response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
					//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
					retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
					MHD_destroy_response(response);
				};
			};
		};

	} else {
		// active/old request (GET: should not go through here ; POST: DPCHAPP, UPLOAD)
		req = (ReqWzsk*) *con_cls;

		if (strcmp(method, "POST") == 0) {
			if (*upload_data_size != 0) {
				MHD_post_process(req->pp, upload_data, *upload_data_size);
				*upload_data_size = 0;

			} else {
				// POST done
				if (req->ixVBasetype == ReqWzsk::VecVBasetype::DPCHAPP) {
					// --- read dispatch, pass on to job processor, and wait for reply to be transmitted
					// cout << "MhdCallback() DPCHAPP request complete" << endl;
					valid = req->request;
					
					if (valid) {
						//cout << string(req->request, req->requestlen) << endl;
						ixWzskVDpch = readDpchApp(xchg, req);
						valid = req->dpchapp;
					};

					if (valid) {
						req->jref = req->dpchapp->jref;
						valid = validateIp(xchg, req);

						if (ixWzskVDpch == VecWzskVDpch::DPCHAPPROOTWZSKLOGIN) req->jref = xchg->jrefRoot;
					};

					if (valid) {
						validateJrefNotify(xchg, req);

						xchg->addReq(req);

						// wait for reply
						req->cReady.lockMutex("WzskcmbdAppsrv", "MhdCallback[3]");
						if (req->ixVState != ReqWzsk::VecVState::REPLY) req->cReady.wait("WzskcmbdAppsrv", "MhdCallback[2]");
						req->cReady.unlockMutex("WzskcmbdAppsrv", "MhdCallback[3]");

						if (req->dpcheng) {
							writeDpchEng(xchg, req);
							response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						} else {
							response = MHD_create_response_from_buffer(strlen(empty), empty, MHD_RESPMEM_PERSISTENT);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						};
					};
					
					if (!valid) {
						response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
						MHD_destroy_response(response);
					};

				} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::UPLOAD) {
					// --- pass notification concerning uploaded file to job processor, and wait for acknowledgement
					valid = validateIp(xchg, req);

					if (valid) {
						validateJrefNotify(xchg, req);

						xchg->addReq(req);

						// wait for reply (usually empty)
						req->cReady.lockMutex("WzskcmbdAppsrv", "MhdCallback[4]");
						if (req->ixVState != ReqWzsk::VecVState::REPLY) req->cReady.wait("WzskcmbdAppsrv", "MhdCallback[3]");
						req->cReady.unlockMutex("WzskcmbdAppsrv", "MhdCallback[4]");

						if (req->reply) {
							response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						} else {
							response = MHD_create_response_from_buffer(strlen(empty), empty, MHD_RESPMEM_PERSISTENT);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						};
					};

					if (!valid) {
						response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
						MHD_destroy_response(response);
					};
				};
			};
		};
	};

	return retval;
};

#ifdef _WIN32
int WzskcmbdAppsrv::MhdFilesend(
			void* con_cls
			, uint64_t pos
			, char* buf
			, int max
		) {
#else
ssize_t WzskcmbdAppsrv::MhdFilesend(
			void* con_cls
			, uint64_t pos
			, char* buf
			, size_t max
		) {
#endif
	ReqWzsk* req = (ReqWzsk*) con_cls;

	int64_t spos = pos;
	int64_t len;

	if (req) {
		// determine length remaining
		req->file->seekg(0, ios::end);
		len = req->file->tellg();
		if (len != -1) {

			if (len > spos) {
				req->file->seekg(spos);
				req->file->read(buf, max);

				// check for errors
				if (req->file->bad()) return 0;

				if (len < (max+spos))
					return (len-spos);
				else
					return max;
			};
		};
	};

	return 0;
};

int WzskcmbdAppsrv::MhdPostrecv(
			void* con_cls
			, MHD_ValueKind kind
			, const char* key
			, const char* filename
			, const char* content_type
			, const char* transfer_encoding
			, const char* data
			, uint64_t off
			, size_t size
		) {
	ReqWzsk* req = (ReqWzsk*) con_cls;

	//cout << "MhdPostrecv() with size = " << ((unsigned int) size) << endl;

	char* olddata;

	if (req->ixVBasetype == ReqWzsk::VecVBasetype::DPCHAPP) {
		// --- copy data into req->request (append if required)
		if (strcmp(key, "xml") != 0) return MHD_NO;

		if (size > 0) {
			if (!req->request) {
				req->request = new char[size];
				memcpy(req->request, data, size);
				req->requestlen = size;

			} else {
				olddata = req->request;

				req->request = new char[req->requestlen + size];
				memcpy(req->request, olddata, req->requestlen);
				memcpy(&(req->request[req->requestlen]), data, size);
				req->requestlen = req->requestlen + size;

				delete[] olddata;
			};
		};

	} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::UPLOAD) {
		// --- write data into file
		if (strcmp(key, "file") != 0) return MHD_NO;

		if (size > 0) {
			req->file = new fstream();

			req->file->open(req->filename.c_str(), fstream::app | fstream::out | fstream::binary);
			req->file->write(data, size);
			req->file->close();

			delete(req->file);
			req->file = NULL;
		};

	} else {
		return MHD_NO;
	};

	return MHD_YES;
};

void WzskcmbdAppsrv::MhdComplete(
			void* cls
			, MHD_Connection* connection
			, void** con_cls
			, MHD_RequestTerminationCode toe
		) {
	ReqWzsk* req;

	//cout << "MhdComplete()" << endl;

	if (*con_cls != NULL) {
		req = (ReqWzsk*) *con_cls;
		delete req;
	};

	*con_cls = NULL;
};

bool WzskcmbdAppsrv::validateIp(
			XchgWzskcmbd* xchg
			, ReqWzsk* req
		) {
	bool retval = true;

	string ip;

	if (req->jref != 0) {
		if (xchg->getBoolvalPreset(VecWzskVPreset::PREWZSKSUSPSESS, req->jref))
					if (req->jref != xchg->getRefPreset(VecWzskVPreset::PREWZSKJREFSESS, req->jref)) retval = false;

		if (retval) {
			ip = xchg->getTxtvalPreset(VecWzskVPreset::PREWZSKIP, req->jref);
			if (ip != req->ip) retval = false;
		};
	};

	return retval;
};

bool WzskcmbdAppsrv::validateJrefNotify(
			XchgWzskcmbd* xchg
			, ReqWzsk* req
		) {
	bool retval = false;

	ubigint jrefNotify;

	DcolWzsk* dcol = NULL;

	jrefNotify = xchg->getRefPreset(VecWzskVPreset::PREWZSKJREFNOTIFY, req->jref);

	dcol = xchg->getDcolByJref(req->jref);

	if (dcol) {
		retval = (jrefNotify == dcol->jref);
		if (!retval) xchg->triggerIxRefCall(NULL, VecWzskVCall::CALLWZSKREFPRESET, dcol->jref, VecWzskVPreset::PREWZSKJREFNOTIFY, dcol->jref);

		dcol->unlockAccess("WzskcmbdAppsrv", "validateJrefNotify");
	};

	return retval;
};

uint WzskcmbdAppsrv::readDpchApp(
			XchgWzskcmbd* xchg
			, ReqWzsk* req
		) {
	uint ixWzskVDpch = 0;

	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	try {
		parseBuffer(req->request, req->requestlen, &doc, &docctx);

		ixWzskVDpch = VecWzskVDpch::getIx(extractRoot(doc));

		if (ixWzskVDpch == VecWzskVDpch::DPCHAPPDLGWZSKFILDOWNLOADDO) {
			req->dpchapp = new DlgWzskFilDownload::DpchAppDo();
			((DlgWzskFilDownload::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPDLGWZSKNAVLOAINIDATA) {
			req->dpchapp = new DlgWzskNavLoaini::DpchAppData();
			((DlgWzskNavLoaini::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPDLGWZSKNAVLOAINIDO) {
			req->dpchapp = new DlgWzskNavLoaini::DpchAppDo();
			((DlgWzskNavLoaini::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPDLGWZSKOBJNEWDATA) {
			req->dpchapp = new DlgWzskObjNew::DpchAppData();
			((DlgWzskObjNew::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPDLGWZSKOBJNEWDO) {
			req->dpchapp = new DlgWzskObjNew::DpchAppDo();
			((DlgWzskObjNew::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPDLGWZSKOGRNEWDATA) {
			req->dpchapp = new DlgWzskOgrNew::DpchAppData();
			((DlgWzskOgrNew::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPDLGWZSKOGRNEWDO) {
			req->dpchapp = new DlgWzskOgrNew::DpchAppDo();
			((DlgWzskOgrNew::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPDLGWZSKSCFCAMERAMATDATA) {
			req->dpchapp = new DlgWzskScfCameramat::DpchAppData();
			((DlgWzskScfCameramat::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPDLGWZSKSCFCAMERAMATDO) {
			req->dpchapp = new DlgWzskScfCameramat::DpchAppDo();
			((DlgWzskScfCameramat::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPDLGWZSKSCFLASERPOSDATA) {
			req->dpchapp = new DlgWzskScfLaserpos::DpchAppData();
			((DlgWzskScfLaserpos::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPDLGWZSKSCFLASERPOSDO) {
			req->dpchapp = new DlgWzskScfLaserpos::DpchAppDo();
			((DlgWzskScfLaserpos::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPDLGWZSKSCFTTABLECOORDDATA) {
			req->dpchapp = new DlgWzskScfTtablecoord::DpchAppData();
			((DlgWzskScfTtablecoord::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPDLGWZSKSCFTTABLECOORDDO) {
			req->dpchapp = new DlgWzskScfTtablecoord::DpchAppDo();
			((DlgWzskScfTtablecoord::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPROOTWZSKLOGIN) {
			req->dpchapp = new RootWzsk::DpchAppLogin();
			((RootWzsk::DpchAppLogin*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKALERT) {
			req->dpchapp = new DpchAppWzskAlert();
			((DpchAppWzskAlert*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKFILDETAILDATA) {
			req->dpchapp = new PnlWzskFilDetail::DpchAppData();
			((PnlWzskFilDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKFILDETAILDO) {
			req->dpchapp = new PnlWzskFilDetail::DpchAppDo();
			((PnlWzskFilDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKFILDO) {
			req->dpchapp = new CrdWzskFil::DpchAppDo();
			((CrdWzskFil::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKFILLISTDATA) {
			req->dpchapp = new PnlWzskFilList::DpchAppData();
			((PnlWzskFilList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKFILLISTDO) {
			req->dpchapp = new PnlWzskFilList::DpchAppDo();
			((PnlWzskFilList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKFILRECDO) {
			req->dpchapp = new PnlWzskFilRec::DpchAppDo();
			((PnlWzskFilRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKINIT) {
			req->dpchapp = new DpchAppWzskInit();
			((DpchAppWzskInit*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLIV2DVIEWALIGN) {
			req->dpchapp = new PnlWzskLiv2DView::DpchAppAlign();
			((PnlWzskLiv2DView::DpchAppAlign*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLIV2DVIEWDATA) {
			req->dpchapp = new PnlWzskLiv2DView::DpchAppData();
			((PnlWzskLiv2DView::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLIV2DVIEWDO) {
			req->dpchapp = new PnlWzskLiv2DView::DpchAppDo();
			((PnlWzskLiv2DView::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLIV3DVIEWDATA) {
			req->dpchapp = new PnlWzskLiv3DView::DpchAppData();
			((PnlWzskLiv3DView::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLIV3DVIEWDO) {
			req->dpchapp = new PnlWzskLiv3DView::DpchAppDo();
			((PnlWzskLiv3DView::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLIVDO) {
			req->dpchapp = new CrdWzskLiv::DpchAppDo();
			((CrdWzskLiv::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLIVSYSMONDO) {
			req->dpchapp = new PnlWzskLivSysmon::DpchAppDo();
			((PnlWzskLivSysmon::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLLVCAMERADATA) {
			req->dpchapp = new PnlWzskLlvCamera::DpchAppData();
			((PnlWzskLlvCamera::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLLVCAMERADO) {
			req->dpchapp = new PnlWzskLlvCamera::DpchAppDo();
			((PnlWzskLlvCamera::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLLVDO) {
			req->dpchapp = new CrdWzskLlv::DpchAppDo();
			((CrdWzskLlv::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLLVLASERDATA) {
			req->dpchapp = new PnlWzskLlvLaser::DpchAppData();
			((PnlWzskLlvLaser::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLLVLASERDO) {
			req->dpchapp = new PnlWzskLlvLaser::DpchAppDo();
			((PnlWzskLlvLaser::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLLVTERMDATA) {
			req->dpchapp = new PnlWzskLlvTerm::DpchAppData();
			((PnlWzskLlvTerm::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLLVTERMDO) {
			req->dpchapp = new PnlWzskLlvTerm::DpchAppDo();
			((PnlWzskLlvTerm::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLLVTTABLEDATA) {
			req->dpchapp = new PnlWzskLlvTtable::DpchAppData();
			((PnlWzskLlvTtable::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLLVTTABLEDO) {
			req->dpchapp = new PnlWzskLlvTtable::DpchAppDo();
			((PnlWzskLlvTtable::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKNAVADMINDATA) {
			req->dpchapp = new PnlWzskNavAdmin::DpchAppData();
			((PnlWzskNavAdmin::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKNAVADMINDO) {
			req->dpchapp = new PnlWzskNavAdmin::DpchAppDo();
			((PnlWzskNavAdmin::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKNAVDO) {
			req->dpchapp = new CrdWzskNav::DpchAppDo();
			((CrdWzskNav::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKNAVGALERYDATA) {
			req->dpchapp = new PnlWzskNavGalery::DpchAppData();
			((PnlWzskNavGalery::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKNAVGALERYDO) {
			req->dpchapp = new PnlWzskNavGalery::DpchAppDo();
			((PnlWzskNavGalery::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKNAVOPDO) {
			req->dpchapp = new PnlWzskNavOp::DpchAppDo();
			((PnlWzskNavOp::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKNAVPREDO) {
			req->dpchapp = new PnlWzskNavPre::DpchAppDo();
			((PnlWzskNavPre::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKOBJ1NSHOTDATA) {
			req->dpchapp = new PnlWzskObj1NShot::DpchAppData();
			((PnlWzskObj1NShot::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKOBJ1NSHOTDO) {
			req->dpchapp = new PnlWzskObj1NShot::DpchAppDo();
			((PnlWzskObj1NShot::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKOBJDETAILDATA) {
			req->dpchapp = new PnlWzskObjDetail::DpchAppData();
			((PnlWzskObjDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKOBJDETAILDO) {
			req->dpchapp = new PnlWzskObjDetail::DpchAppDo();
			((PnlWzskObjDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKOBJDO) {
			req->dpchapp = new CrdWzskObj::DpchAppDo();
			((CrdWzskObj::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKOBJLISTDATA) {
			req->dpchapp = new PnlWzskObjList::DpchAppData();
			((PnlWzskObjList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKOBJLISTDO) {
			req->dpchapp = new PnlWzskObjList::DpchAppDo();
			((PnlWzskObjList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKOBJRECDO) {
			req->dpchapp = new PnlWzskObjRec::DpchAppDo();
			((PnlWzskObjRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKOBJREF1NFILEDATA) {
			req->dpchapp = new PnlWzskObjRef1NFile::DpchAppData();
			((PnlWzskObjRef1NFile::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKOBJREF1NFILEDO) {
			req->dpchapp = new PnlWzskObjRef1NFile::DpchAppDo();
			((PnlWzskObjRef1NFile::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKOGR1NOBJECTDATA) {
			req->dpchapp = new PnlWzskOgr1NObject::DpchAppData();
			((PnlWzskOgr1NObject::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKOGR1NOBJECTDO) {
			req->dpchapp = new PnlWzskOgr1NObject::DpchAppDo();
			((PnlWzskOgr1NObject::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKOGRDETAILDATA) {
			req->dpchapp = new PnlWzskOgrDetail::DpchAppData();
			((PnlWzskOgrDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKOGRDETAILDO) {
			req->dpchapp = new PnlWzskOgrDetail::DpchAppDo();
			((PnlWzskOgrDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKOGRDO) {
			req->dpchapp = new CrdWzskOgr::DpchAppDo();
			((CrdWzskOgr::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKOGRLISTDATA) {
			req->dpchapp = new PnlWzskOgrList::DpchAppData();
			((PnlWzskOgrList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKOGRLISTDO) {
			req->dpchapp = new PnlWzskOgrList::DpchAppDo();
			((PnlWzskOgrList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKOGRRECDO) {
			req->dpchapp = new PnlWzskOgrRec::DpchAppDo();
			((PnlWzskOgrRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKOGRSUP1NOBJGROUPDATA) {
			req->dpchapp = new PnlWzskOgrSup1NObjgroup::DpchAppData();
			((PnlWzskOgrSup1NObjgroup::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKOGRSUP1NOBJGROUPDO) {
			req->dpchapp = new PnlWzskOgrSup1NObjgroup::DpchAppDo();
			((PnlWzskOgrSup1NObjgroup::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKPRSADETAILDATA) {
			req->dpchapp = new PnlWzskPrsADetail::DpchAppData();
			((PnlWzskPrsADetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKPRSADETAILDO) {
			req->dpchapp = new PnlWzskPrsADetail::DpchAppDo();
			((PnlWzskPrsADetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKPRSDETAILDATA) {
			req->dpchapp = new PnlWzskPrsDetail::DpchAppData();
			((PnlWzskPrsDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKPRSDETAILDO) {
			req->dpchapp = new PnlWzskPrsDetail::DpchAppDo();
			((PnlWzskPrsDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKPRSDO) {
			req->dpchapp = new CrdWzskPrs::DpchAppDo();
			((CrdWzskPrs::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKPRSLISTDATA) {
			req->dpchapp = new PnlWzskPrsList::DpchAppData();
			((PnlWzskPrsList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKPRSLISTDO) {
			req->dpchapp = new PnlWzskPrsList::DpchAppDo();
			((PnlWzskPrsList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKPRSRECDO) {
			req->dpchapp = new PnlWzskPrsRec::DpchAppDo();
			((PnlWzskPrsRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKRESUME) {
			req->dpchapp = new DpchAppWzskResume();
			((DpchAppWzskResume*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKSCFCONNDO) {
			req->dpchapp = new PnlWzskScfConn::DpchAppDo();
			((PnlWzskScfConn::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKSCFDO) {
			req->dpchapp = new CrdWzskScf::DpchAppDo();
			((CrdWzskScf::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKSCFGEOMDO) {
			req->dpchapp = new PnlWzskScfGeom::DpchAppDo();
			((PnlWzskScfGeom::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKSES1NSHOTDATA) {
			req->dpchapp = new PnlWzskSes1NShot::DpchAppData();
			((PnlWzskSes1NShot::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKSES1NSHOTDO) {
			req->dpchapp = new PnlWzskSes1NShot::DpchAppDo();
			((PnlWzskSes1NShot::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKSESDETAILDATA) {
			req->dpchapp = new PnlWzskSesDetail::DpchAppData();
			((PnlWzskSesDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKSESDETAILDO) {
			req->dpchapp = new PnlWzskSesDetail::DpchAppDo();
			((PnlWzskSesDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKSESDO) {
			req->dpchapp = new CrdWzskSes::DpchAppDo();
			((CrdWzskSes::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKSESLISTDATA) {
			req->dpchapp = new PnlWzskSesList::DpchAppData();
			((PnlWzskSesList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKSESLISTDO) {
			req->dpchapp = new PnlWzskSesList::DpchAppDo();
			((PnlWzskSesList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKSESRECDO) {
			req->dpchapp = new PnlWzskSesRec::DpchAppDo();
			((PnlWzskSesRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKSHTAPARDATA) {
			req->dpchapp = new PnlWzskShtAPar::DpchAppData();
			((PnlWzskShtAPar::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKSHTAPARDO) {
			req->dpchapp = new PnlWzskShtAPar::DpchAppDo();
			((PnlWzskShtAPar::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKSHTDETAILDATA) {
			req->dpchapp = new PnlWzskShtDetail::DpchAppData();
			((PnlWzskShtDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKSHTDETAILDO) {
			req->dpchapp = new PnlWzskShtDetail::DpchAppDo();
			((PnlWzskShtDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKSHTDO) {
			req->dpchapp = new CrdWzskSht::DpchAppDo();
			((CrdWzskSht::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKSHTLISTDATA) {
			req->dpchapp = new PnlWzskShtList::DpchAppData();
			((PnlWzskShtList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKSHTLISTDO) {
			req->dpchapp = new PnlWzskShtList::DpchAppDo();
			((PnlWzskShtList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKSHTRECDO) {
			req->dpchapp = new PnlWzskShtRec::DpchAppDo();
			((PnlWzskShtRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKSHTREF1NFILEDATA) {
			req->dpchapp = new PnlWzskShtRef1NFile::DpchAppData();
			((PnlWzskShtRef1NFile::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKSHTREF1NFILEDO) {
			req->dpchapp = new PnlWzskShtRef1NFile::DpchAppDo();
			((PnlWzskShtRef1NFile::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKUSGAACCESSDATA) {
			req->dpchapp = new PnlWzskUsgAAccess::DpchAppData();
			((PnlWzskUsgAAccess::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKUSGAACCESSDO) {
			req->dpchapp = new PnlWzskUsgAAccess::DpchAppDo();
			((PnlWzskUsgAAccess::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKUSGDETAILDATA) {
			req->dpchapp = new PnlWzskUsgDetail::DpchAppData();
			((PnlWzskUsgDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKUSGDETAILDO) {
			req->dpchapp = new PnlWzskUsgDetail::DpchAppDo();
			((PnlWzskUsgDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKUSGDO) {
			req->dpchapp = new CrdWzskUsg::DpchAppDo();
			((CrdWzskUsg::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKUSGLISTDATA) {
			req->dpchapp = new PnlWzskUsgList::DpchAppData();
			((PnlWzskUsgList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKUSGLISTDO) {
			req->dpchapp = new PnlWzskUsgList::DpchAppDo();
			((PnlWzskUsgList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKUSGMNUSERDATA) {
			req->dpchapp = new PnlWzskUsgMNUser::DpchAppData();
			((PnlWzskUsgMNUser::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKUSGMNUSERDO) {
			req->dpchapp = new PnlWzskUsgMNUser::DpchAppDo();
			((PnlWzskUsgMNUser::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKUSGRECDO) {
			req->dpchapp = new PnlWzskUsgRec::DpchAppDo();
			((PnlWzskUsgRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKUSR1NSESSIONDATA) {
			req->dpchapp = new PnlWzskUsr1NSession::DpchAppData();
			((PnlWzskUsr1NSession::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKUSR1NSESSIONDO) {
			req->dpchapp = new PnlWzskUsr1NSession::DpchAppDo();
			((PnlWzskUsr1NSession::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKUSRAACCESSDATA) {
			req->dpchapp = new PnlWzskUsrAAccess::DpchAppData();
			((PnlWzskUsrAAccess::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKUSRAACCESSDO) {
			req->dpchapp = new PnlWzskUsrAAccess::DpchAppDo();
			((PnlWzskUsrAAccess::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKUSRDETAILDATA) {
			req->dpchapp = new PnlWzskUsrDetail::DpchAppData();
			((PnlWzskUsrDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKUSRDETAILDO) {
			req->dpchapp = new PnlWzskUsrDetail::DpchAppDo();
			((PnlWzskUsrDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKUSRDO) {
			req->dpchapp = new CrdWzskUsr::DpchAppDo();
			((CrdWzskUsr::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKUSRLISTDATA) {
			req->dpchapp = new PnlWzskUsrList::DpchAppData();
			((PnlWzskUsrList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKUSRLISTDO) {
			req->dpchapp = new PnlWzskUsrList::DpchAppDo();
			((PnlWzskUsrList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKUSRMNUSERGROUPDATA) {
			req->dpchapp = new PnlWzskUsrMNUsergroup::DpchAppData();
			((PnlWzskUsrMNUsergroup::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKUSRMNUSERGROUPDO) {
			req->dpchapp = new PnlWzskUsrMNUsergroup::DpchAppDo();
			((PnlWzskUsrMNUsergroup::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKUSRRECDO) {
			req->dpchapp = new PnlWzskUsrRec::DpchAppDo();
			((PnlWzskUsrRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		};
	} catch (SbeException& e) {
	};

	if (docctx) xmlXPathFreeContext(docctx);
	if (doc) xmlFreeDoc(doc);
	
	return ixWzskVDpch;
};

void WzskcmbdAppsrv::writeDpchEng(
			XchgWzskcmbd* xchg
			, ReqWzsk* req
		) {
	xmlBuffer* buf = NULL;
	xmlTextWriter* wr = NULL;

	startwriteBuffer(&wr, &buf);

	if (req->dpcheng) {
		req->dpcheng->writeXML(req->ixWzskVLocale, wr);
	} else {
		DpchEngWzskConfirm dpchconfirm(false, req->jref, "");
		dpchconfirm.writeXML(req->ixWzskVLocale, wr);
	};

	closewriteBuffer(wr);

	req->replylen = buf->use;
	req->reply = new char[req->replylen];
	memcpy(req->reply, buf->content, req->replylen);

	xmlBufferFree(buf);
};

