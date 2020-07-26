/**
  * \file PnlWzskOgrRec.js
  * web client functionality for panel PnlWzskOgrRec
  * \author Catherine Johnson
  * \date created: 23 Jul 2020
  * \date modified: 23 Jul 2020
  */

function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrWzskOgrRec", "scrJrefDetail");
	scrJref1NShot = retrieveSi(srcdoc, "StatShrWzskOgrRec", "scrJref1NShot");
	scrJref1NObject = retrieveSi(srcdoc, "StatShrWzskOgrRec", "scrJref1NObject");
	scrJrefSup1NObjgroup = retrieveSi(srcdoc, "StatShrWzskOgrRec", "scrJrefSup1NObjgroup");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppWzskOgrRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppWzskOgrRec", "initdone1NShot", "false");
	setSi(srcdoc, "StatAppWzskOgrRec", "initdone1NObject", "false");
	setSi(srcdoc, "StatAppWzskOgrRec", "initdoneSup1NObjgroup", "false");
};

function resetHeights() {
	heightDetail = 30;
	height1NShot = 30;
	height1NObject = 30;
	heightSup1NObjgroup = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppWzskOgrRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppWzskOgrRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWzskOgrRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppWzskOgrRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppWzskOgrRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWzskOgrRec", "initdoneDetail") == "true");
	var initdone1NShot = (retrieveSi(srcdoc, "StatAppWzskOgrRec", "initdone1NShot") == "true");
	var initdone1NObject = (retrieveSi(srcdoc, "StatAppWzskOgrRec", "initdone1NObject") == "true");
	var initdoneSup1NObjgroup = (retrieveSi(srcdoc, "StatAppWzskOgrRec", "initdoneSup1NObjgroup") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlWzskOgrDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdone1NShot) {
		rhsdoc.getElementById("1NShot").src = "./PnlWzskOgr1NShot.html?scrJref=" + scrJref1NShot;
	} else if (!initdone1NObject) {
		rhsdoc.getElementById("1NObject").src = "./PnlWzskOgr1NObject.html?scrJref=" + scrJref1NObject;
	} else if (!initdoneSup1NObjgroup) {
		rhsdoc.getElementById("Sup1NObjgroup").src = "./PnlWzskOgrSup1NObjgroup.html?scrJref=" + scrJrefSup1NObjgroup;

	} else {
		refreshB();
	};
};

function reinitPnl(scrJrefPnl) {
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Detail")) lhsrhsdoc = lhsdoc;
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
		else if (short == "1NShot") height1NShot = height;
		else if (short == "1NObject") height1NObject = height;
		else if (short == "Sup1NObjgroup") heightSup1NObjgroup = height;
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

	doc.getElementById("Rec_side").src = "./PnlWzskOgrRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlWzskOgrRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 180);
	doc.getElementById("tdSide").setAttribute("height", "180");
	doc.getElementById("Rec_side").setAttribute("height", "180");
	doc.getElementById("Rec_cont").setAttribute("height", "180");

	doc.getElementById("Rec_side").src = "./PnlWzskOgrRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlWzskOgrRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Detail")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "1NShot") height1NShot = height;
	else if (pnlshort == "1NObject") height1NObject = height;
	else if (pnlshort == "Sup1NObjgroup") heightSup1NObjgroup = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + 5;
	heightRhs = height1NShot+13 + height1NObject+13 + heightSup1NObjgroup+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWzskOgrRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWzskOgrRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskOgrRec", "srefIxWzskVExpstate");

	if (srefIxWzskVExpstate == "mind") {
		minimize();
	} else if (srefIxWzskVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrWzskOgrRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWzskOgrRec", "TxtRef"));
};

function refreshB() {

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWzskOgrRec", "TxtRef"));

};

function refresh() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskOgrRec", "srefIxWzskVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskOgrRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzskOgrRecData", "ContInfWzskOgrRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzskOgrRecData", "StatAppWzskOgrRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWzskOgrRecData", "StatShrWzskOgrRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskOgrRecData", "TagWzskOgrRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (!srcdoc) return;

	var _scrJref, mask;
	var srefIxWzskVExpstate, newSrefIxWzskVExpstate;

	_scrJref = retrieveValue(dom, "//wzsk:*/wzsk:scrJref");
	srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskOgrRec", "srefIxWzskVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngWzskOgrRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskOgrRec", "srefIxWzskVExpstate");

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
			} else if (_scrJref == scrJref1NShot) {
				if (getInitdone("1NShot")) rhsdoc.getElementById("1NShot").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NObject) {
				if (getInitdone("1NObject")) rhsdoc.getElementById("1NObject").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefSup1NObjgroup) {
				if (getInitdone("Sup1NObjgroup")) rhsdoc.getElementById("Sup1NObjgroup").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngWzskOgrRecData") {
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

			} else if (blk.nodeName == "DpchEngWzskOgrRecData") {
				srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskOgrRec", "srefIxWzskVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskOgrRec", "srefIxWzskVExpstate");

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

