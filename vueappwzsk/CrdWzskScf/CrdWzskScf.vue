<template>
	<v-container v-if="initdone">
		<h1 class="text-5 my-3" style="text-align:center">System configuration</h1>
		<PnlWzskScfConn
			v-on:request="handleRequest"
			ref="PnlWzskScfConn"
			:scrJref=statshr.scrJrefConn
		/>
		<PnlWzskScfGeom
			v-on:request="handleRequest"
			ref="PnlWzskScfGeom"
			:scrJref=statshr.scrJrefGeom
		/>
	</v-container>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	*/
	import PnlWzskScfConn from './PnlWzskScfConn';
	import PnlWzskScfGeom from './PnlWzskScfGeom';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWzskScf',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWzskScfConn,
			PnlWzskScfGeom
			/*
			*/
		},

		mounted() {
			//console.log("CrdWzskScf.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzskInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				var dlgopen = false;
				var dlgclose = false;

				var srefDlg = "";
				var scrJrefDlg = "";

				if (dpcheng.ContInfWzskScf) this.continf = dpcheng.ContInfWzskScf;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWzskScf) this.statapp = dpcheng.StatAppWzskScf;
				if (dpcheng.StatShrWzskScf) {
					if (this.statshr != null) {
						dlgopen = ((dpcheng.StatShrWzskScf.scrJrefDlgcameramat != "") || (dpcheng.StatShrWzskScf.scrJrefDlglaserpos != "") || (dpcheng.StatShrWzskScf.scrJrefDlgttablecoord != ""));
						dlgclose = ((this.statshr.scrJrefDlgcameramat != "") || (this.statshr.scrJrefDlglaserpos != "") || (this.statshr.scrJrefDlgttablecoord != ""));
						if (dlgopen && dlgclose) {
							dlgopen = false;
							dlgclose = false;
						}
						if (dlgopen) {
							if (dpcheng.StatShrWzskScf.scrJrefDlgcameramat != "") {
								srefDlg = "DlgWzskScfCameramat";
								scrJrefDlg = dpcheng.StatShrWzskScf.scrJrefDlgcameramat;
							} else if (dpcheng.StatShrWzskScf.scrJrefDlglaserpos != "") {
								srefDlg = "DlgWzskScfLaserpos";
								scrJrefDlg = dpcheng.StatShrWzskScf.scrJrefDlglaserpos;
							} else if (dpcheng.StatShrWzskScf.scrJrefDlgttablecoord != "") {
								srefDlg = "DlgWzskScfTtablecoord";
								scrJrefDlg = dpcheng.StatShrWzskScf.scrJrefDlgttablecoord;
							}
						}
					}
					this.statshr = dpcheng.StatShrWzskScf;
				}
				if (dpcheng.TagWzskScf) {
					Wzsk.unescapeBlock(dpcheng.TagWzskScf);
					this.tag = dpcheng.TagWzskScf;
				}

				if (dlgopen) this.$emit("dlgopen", {srefDlg: srefDlg, scrJrefDlg: scrJrefDlg});
				else if (dlgclose) this.$emit("dlgclose");
				/*
				*/
			},

			handleCrdopen: function(obj) {
				this.$emit("crdopen", obj)
			},

			handleRequest: function(obj) {
				this.$emit("request", obj)
			},

			handleReply: function(obj) {
				if (obj.scrJref == this.scrJref) {
					if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);

				} else if (this.initdone) {
					/*
					*/
					if (obj.scrJref == this.statshr.scrJrefConn) this.$refs.PnlWzskScfConn.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefGeom) this.$refs.PnlWzskScfGeom.handleReply(obj);
					else console.log("got a '" + obj.srefIxWzskVDpch + "' from job with scrJref " + obj.dpcheng.scrJref);
					/*
					*/
				}
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWzskVDpch == "DpchEngWzskScfData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefConn) {
						this.$refs.PnlWzskScfConn.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefGeom) {
						this.$refs.PnlWzskScfGeom.handleUpdate(obj);
						processed = true;
					}
					/*
					*/
				}

				//if (!processed) console.log("got a '" + obj.srefIxWzskVDpch + "' from job with scrJref " + obj.dpcheng.scrJref);

				return processed
			},
		},

		data: () => ({
			initdone: false,

			/*
			*/
			continf: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			tag: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
