// IP cust --- INSERT

// --- view initialization and refresh
function initPlh() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initPlh --- BEGIN
	// IP initPlh --- END

	setSi(srcdoc, "StatAppDlgWzskScfTtablecoord", "initdone", "true");

	refreshPlh();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWzskScfTtablecoord", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWzskScfTtablecoord", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWzskScfTtablecoord", "numFDse"));

	var active, sref, Title;

	var myspan, myrect;

	for (var num = 1; num <= 1; num++) {
		sref = retrieveValue(srcdoc, "//wzsk:FeedFDse/wzsk:Fi[@num='" + num + "']/wzsk:sref");
		Title = retrieveValue(srcdoc, "//wzsk:FeedFDse/wzsk:Fi[@num='" + num + "']/wzsk:tit1");

		myspan = hdrdoc.getElementById("Cpt" + sref);
		myrect = hdrdoc.getElementById("Dit" + sref);

		setTextContent(hdrdoc, myspan, Title);

		if (num == numFDse) {
			myspan.setAttribute("class", "hdr_ditsel");
			myrect.setAttribute("class", "hdr_ditsels");
		} else {
			myspan.setAttribute("class", "hdr_dit");
			myspan.setAttribute("onclick", "handleDseSelect(" + num + ")");
			myrect.setAttribute("class", "hdr_dits");
			myrect.setAttribute("onclick", "handleDseSelect(" + num + ")");
		};
	};
};

function refreshPlh() {
	// IP refreshPlh.vars --- BEGIN
	// IP refreshPlh.vars --- END

	// IP refreshPlh --- BEGIN
	// IP refreshPlh --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgWzskScfTtablecoord", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);
	var initdone = (retrieveSi(srcdoc, "StatAppDlgWzskScfTtablecoord", "initdone") == "true");

	// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgWzskScfTtablecoord", "ButDneActive") == "true");
	// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgWzskScfTtablecoord" + shortDit + ".xml" 

	} else if (initdone) {
		// update current dialog item
		if (shortDit == "Plh") {
			refreshPlh();
		};
	};

	// IP refresh --- BEGIN
	refreshBut(ftrdoc, "ButDne", ButDneActive, false);
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

// --- specific event handlers for app controls of dialog item Plh

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgWzskScfTtablecoordDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWzskScfTtablecoord", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgWzskScfTtablecoord", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgWzskScfTtablecoord", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWzskScfTtablecoordData", scrJref, "ContIacDlgWzskScfTtablecoord");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWzskScfTtablecoordData", "ContIacDlgWzskScfTtablecoord", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWzskScfTtablecoordData", "ContInfDlgWzskScfTtablecoord", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWzskScfTtablecoordData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgWzskScfTtablecoordData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWzskScfTtablecoordData", "StatAppDlgWzskScfTtablecoord", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWzskScfTtablecoordData", "StatShrDlgWzskScfTtablecoord", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWzskScfTtablecoordData", "TagDlgWzskScfTtablecoord", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgWzskScfTtablecoordData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgWzskScfTtablecoordData") {
		handleDpchEngDlgWzskScfTtablecoordData(dom);
	};
};

function handleDpchEngDlgWzskScfTtablecoordData(dom) {
	// IP handleDpchEngDlgWzskScfTtablecoordData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wzsk:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWzskScfTtablecoordData") {
				mergeDpchEngData(dom);
				init();
			};
		};
	};
};

function handleDpchAppDataDoReply() {
	var dom, blk, mask;

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

			} else if (blk.nodeName == "DpchEngDlgWzskScfTtablecoordData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};
