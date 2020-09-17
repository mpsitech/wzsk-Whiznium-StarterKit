/**
  * \file DlgWzskOgrNew.js
  * web client functionality for dialog DlgWzskOgrNew
  * \author Catherine Johnson
  * \date created: 16 Sep 2020
  * \date modified: 16 Sep 2020
  */

// IP cust --- INSERT

// --- view initialization and refresh
function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	contdoc = doc.getElementById("_cont").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWzskOgrNew", "Cpt"));

	initCpt(contdoc, "CptSup", retrieveTi(srcdoc, "TagDlgWzskOgrNew", "CptSup"));
	initCpt(contdoc, "CptSrf", retrieveTi(srcdoc, "TagDlgWzskOgrNew", "CptSrf"));
	initCpt(contdoc, "CptLcl", retrieveTi(srcdoc, "TagDlgWzskOgrNew", "CptLcl"));
	refreshPup(contdoc, srcdoc, "PupLcl", "", "FeedFPupLcl", retrieveCi(srcdoc, "ContIacDlgWzskOgrNew", "numFPupLcl"), true, false);
	initCpt(contdoc, "CptTit", retrieveTi(srcdoc, "TagDlgWzskOgrNew", "CptTit"));
	initCpt(contdoc, "CptCmt", retrieveTi(srcdoc, "TagDlgWzskOgrNew", "CptCmt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButCnc"), retrieveTi(srcdoc, "TagDlgWzskOgrNew", "ButCnc"));
	setTextContent(ftrdoc, ftrdoc.getElementById("ButCre"), "\u00a0\u00a0" + retrieveTi(srcdoc, "TagDlgWzskOgrNew", "ButCre"));

	refresh();
};

function refresh() {
	// IP refresh.vars --- BEGIN

	var ButCncActive = (retrieveSi(srcdoc, "StatShrDlgWzskOgrNew", "ButCncActive") == "true");
	var ButCreActive = (retrieveSi(srcdoc, "StatShrDlgWzskOgrNew", "ButCreActive") == "true");
	// IP refresh.vars --- END

	// IP refresh --- BEGIN
	refreshPup(contdoc, srcdoc, "PupSup", "", "FeedFPupSup", retrieveCi(srcdoc, "ContIacDlgWzskOgrNew", "numFPupSup"), true, false);

	refreshTxf(contdoc, "TxfSrf", "s", retrieveCi(srcdoc, "ContIacDlgWzskOgrNew", "TxfSrf"), true, false, true);

	contdoc.getElementById("PupLcl").value = retrieveCi(srcdoc, "ContIacDlgWzskOgrNew", "numFPupLcl");

	refreshTxf(contdoc, "TxfTit", "", retrieveCi(srcdoc, "ContIacDlgWzskOgrNew", "TxfTit"), true, false, true);

	refreshTxft(contdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacDlgWzskOgrNew", "TxfCmt"), true, false, true);

	refreshBut(ftrdoc, "ButCnc", ButCncActive, false);
	refreshBut(ftrdoc, "ButCre", ButCreActive, false);
	// IP refresh --- END
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppDlgWzskOgrNewDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacDlgWzskOgrNew", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWzskOgrNewData", scrJref, "ContIacDlgWzskOgrNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacDlgWzskOgrNew", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWzskOgrNewData", scrJref, "ContIacDlgWzskOgrNew");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacDlgWzskOgrNew", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWzskOgrNewData", scrJref, "ContIacDlgWzskOgrNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxftKey(_doc, ctlsref, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	return true;
};

function handleTxftChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	setCi(srcdoc, "ContIacDlgWzskOgrNew", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWzskOgrNewData", scrJref, "ContIacDlgWzskOgrNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWzskOgrNewData", "ContIacDlgWzskOgrNew", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWzskOgrNewData", "ContInfDlgWzskOgrNew", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWzskOgrNewData", "FeedFPupLcl", srcdoc)) mask.push("feedFPupLcl");
	if (updateSrcblock(dom, "DpchEngDlgWzskOgrNewData", "FeedFPupSup", srcdoc)) mask.push("feedFPupSup");
	if (updateSrcblock(dom, "DpchEngDlgWzskOgrNewData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWzskOgrNewData", "StatAppDlgWzskOgrNew", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWzskOgrNewData", "StatShrDlgWzskOgrNew", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWzskOgrNewData", "TagDlgWzskOgrNew", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngDlgWzskOgrNewData") {
		mergeDpchEngData(dom);
		refresh();
	} else if (dpch == "DpchEngDlgWzskOgrNewData") {
		handleDpchEngDlgWzskOgrNewData(dom);
	};
};

function handleDpchEngDlgWzskOgrNewData(dom) {
	// IP handleDpchEngDlgWzskOgrNewData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wzsk:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWzskOgrNewData") {
				mergeDpchEngData(dom);
				init();
			};
		};
	};
};

function handleDpchAppDataDoReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//wzsk:*");

		if (blk) {
			if (blk.nodeName == "DpchEngWzskConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngWzskAlert") {
				getCrdwnd().showAlr(retrieveValue(dom, "//wzsk:DpchEngWzskAlert/wzsk:scrJref"),
							retrieveBlock(dom, "//wzsk:DpchEngWzskAlert/wzsk:ContInfWzskAlert"),
							retrieveBlock(dom, "//wzsk:DpchEngWzskAlert/wzsk:FeedFMcbAlert"));;

			} else if (blk.nodeName == "DpchEngDlgWzskOgrNewData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

