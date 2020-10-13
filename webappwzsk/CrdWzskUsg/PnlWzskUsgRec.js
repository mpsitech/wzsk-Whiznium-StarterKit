/**
  * \file PnlWzskUsgRec.js
  * web client functionality for panel PnlWzskUsgRec
  * \author Catherine Johnson
  * \date created: 13 Oct 2020
  * \date modified: 13 Oct 2020
  */

function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrWzskUsgRec", "scrJrefDetail");
	scrJrefAAccess = retrieveSi(srcdoc, "StatShrWzskUsgRec", "scrJrefAAccess");
	scrJrefMNUser = retrieveSi(srcdoc, "StatShrWzskUsgRec", "scrJrefMNUser");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppWzskUsgRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppWzskUsgRec", "initdoneAAccess", "false");
	setSi(srcdoc, "StatAppWzskUsgRec", "initdoneMNUser", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightAAccess = 30;
	heightMNUser = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppWzskUsgRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppWzskUsgRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWzskUsgRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppWzskUsgRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppWzskUsgRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWzskUsgRec", "initdoneDetail") == "true");
	var initdoneAAccess = (retrieveSi(srcdoc, "StatAppWzskUsgRec", "initdoneAAccess") == "true");
	var initdoneMNUser = (retrieveSi(srcdoc, "StatAppWzskUsgRec", "initdoneMNUser") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlWzskUsgDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneAAccess) {
		lhsdoc.getElementById("AAccess").src = "./PnlWzskUsgAAccess.html?scrJref=" + scrJrefAAccess;
	} else if (!initdoneMNUser) {
		rhsdoc.getElementById("MNUser").src = "./PnlWzskUsgMNUser.html?scrJref=" + scrJrefMNUser;

	} else {
		refreshB();
	};
};

function reinitPnl(scrJrefPnl) {
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Detail") || (short == "AAccess")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	var oldAvail = (lhsrhsdoc.getElementById("tr" + short).getAttribute("class") == "show");

	var height;

	if (avail != oldAvail) {
		if (avail) {
			height = 30;

			lhsrhsdoc.getElementById("spc" + short).setAttribute("class", "show");
			lhsrhsdoc.getElementById("tr" + short).setAttribute("class", "show");

		} else {
			height = -13;

			lhsrhsdoc.getElementById(short).contentWindow.minimize(false);
			
			lhsrhsdoc.getElementById("spc" + short).setAttribute("class", "hide");
			lhsrhsdoc.getElementById("tr" + short).setAttribute("class", "hide");
		};

		if (short == "Headbar") heightHeadbar = height;
		else if (short == "List") heightList = height;
		else if (short == "Rec") heightRec = height;
		else if (short == "Detail") heightDetail = height;
		else if (short == "AAccess") heightAAccess = height;
		else if (short == "MNUser") heightMNUser = height;
	};

	return(avail != oldAvail);
};

// --- expand state management
function minimize() {
	resetInitdones();

	getCrdwnd().changeHeight("Rec", 45);
	doc.getElementById("tdSide").setAttribute("height", "45");
	doc.getElementById("Rec_side").setAttribute("height", "45");
	doc.getElementById("Rec_cont").setAttribute("height", "45");

	doc.getElementById("Rec_side").src = "./PnlWzskUsgRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlWzskUsgRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 137);
	doc.getElementById("tdSide").setAttribute("height", "137");
	doc.getElementById("Rec_side").setAttribute("height", "137");
	doc.getElementById("Rec_cont").setAttribute("height", "137");

	doc.getElementById("Rec_side").src = "./PnlWzskUsgRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlWzskUsgRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Detail") || (pnlshort == "AAccess")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "AAccess") heightAAccess = height;
	else if (pnlshort == "MNUser") heightMNUser = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + heightAAccess+13 + 5;
	heightRhs = heightMNUser+13 + 5;

	if (heightLhs > heightRhs) {
		lhsdoc.getElementById("tdFill").setAttribute("height", "5");
		rhsdoc.getElementById("tdFill").setAttribute("height", "" + (heightLhs-heightRhs+5));

		heightGt = heightLhs;

	} else {
		lhsdoc.getElementById("tdFill").setAttribute("height", "" + (heightRhs-heightLhs+5));
		rhsdoc.getElementById("tdFill").setAttribute("height", "5");

		heightGt = heightRhs;
	};

	getCrdwnd().changeHeight("Rec", 45+heightGt+1);

	doc.getElementById("tdSide").setAttribute("height", "" + (45+heightGt+1));
	doc.getElementById("Rec_side").setAttribute("height", "" + (45+heightGt+1));
	doc.getElementById("Rec_cont").setAttribute("height", "" + (45+heightGt+1));

	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (heightGt+1));

	contdoc.getElementById("tdLhs").setAttribute("height", "" + heightGt);
	contdoc.getElementById("Rec_lhs").setAttribute("height", "" + heightGt);
	contdoc.getElementById("tdRhs").setAttribute("height", "" + heightGt);
	contdoc.getElementById("Rec_rhs").setAttribute("height", "" + heightGt);
};

// --- view initialization and refresh
function initAside() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;

	refreshAside();
};

function initA() {
	if (!doc) return;

	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = null;
	lhsdoc = null;
	rhsdoc = null;

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWzskUsgRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWzskUsgRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskUsgRec", "srefIxWzskVExpstate");

	if (srefIxWzskVExpstate == "mind") {
		minimize();
	} else if (srefIxWzskVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrWzskUsgRec", "ButRegularizeActive") == "true");

	if (ButRegularizeActive) {
		sidedoc.getElementById("ButRegularize").src = "../icon/regularize.png";
		sidedoc.getElementById("ButRegularize").setAttribute("class", "side_pm");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseover", "src='../icon/regularize_hlt.png'");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseout", "src='../icon/regularize.png'");
		sidedoc.getElementById("ButRegularize").setAttribute("onclick", "handleButRegularizeClick()");
	} else {
		sidedoc.getElementById("ButRegularize").src = "../icon/regularize_inact.png";
		sidedoc.getElementById("ButRegularize").setAttribute("class", "side_pmdis");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseover", "");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseout", "");
		sidedoc.getElementById("ButRegularize").setAttribute("onclick", "");
	};
};

function refreshA() {
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWzskUsgRec", "TxtRef"));
};

function refreshB() {

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWzskUsgRec", "TxtRef"));

};

function refresh() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskUsgRec", "srefIxWzskVExpstate");

	if (srefIxWzskVExpstate == "mind") {
		refreshAside();
		refreshA();
	} else if (srefIxWzskVExpstate == "regd") {
		refreshB();
	};
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Rec_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskUsgRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzskUsgRecData", "ContInfWzskUsgRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzskUsgRecData", "StatAppWzskUsgRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWzskUsgRecData", "StatShrWzskUsgRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskUsgRecData", "TagWzskUsgRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (!srcdoc) return;

	var _scrJref, mask;
	var srefIxWzskVExpstate, newSrefIxWzskVExpstate;

	_scrJref = retrieveValue(dom, "//wzsk:*/wzsk:scrJref");
	srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskUsgRec", "srefIxWzskVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngWzskUsgRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskUsgRec", "srefIxWzskVExpstate");

				if (newSrefIxWzskVExpstate != srefIxWzskVExpstate) {
					updateScrJrefs();
					
					if (newSrefIxWzskVExpstate == "mind") {
						minimize();
					} else if (newSrefIxWzskVExpstate == "regd") {
						regularize();
					};

				} else {
					refresh();
				};

			} else {
				refresh();
			};
		};

	} else {
		if (srefIxWzskVExpstate != "mind") {
			if (!lhsdoc) return;
			if (!rhsdoc) return;

			if (_scrJref == scrJrefDetail) {
				if (getInitdone("Detail")) lhsdoc.getElementById("Detail").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefAAccess) {
				if (getInitdone("AAccess")) lhsdoc.getElementById("AAccess").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNUser) {
				if (getInitdone("MNUser")) rhsdoc.getElementById("MNUser").contentWindow.handleDpchEng(dom, dpch);
			} else {
				// alert("got a '" + dpch + "' from job with scrJref " + _scrJref);
			};

		} else {
			// alert("got a '" + dpch + "' from job with scrJref " + _scrJref);
		};
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wzsk:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWzskUsgRecData") {
				mergeDpchEngData(dom);

				updateScrJrefs();
				init();

				getCrdwnd().setInitdone("Rec");
			};
		};
	};
};

function handleDpchAppDataDoReply() {
	var dom, blk, mask;
	var srefIxWzskVExpstate, newSrefIxWzskVExpstate;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//wzsk:*");

		if (blk) {
			if (blk.nodeName == "DpchEngWzskConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngWzskUsgRecData") {
				srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskUsgRec", "srefIxWzskVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskUsgRec", "srefIxWzskVExpstate");

					if (newSrefIxWzskVExpstate != srefIxWzskVExpstate) {
						updateScrJrefs();

						if (newSrefIxWzskVExpstate == "mind") {
							minimize();
						} else if (newSrefIxWzskVExpstate == "regd") {
							regularize();
						};
					};

				} else {
					refresh();
				};
			};
		};
	};
};

